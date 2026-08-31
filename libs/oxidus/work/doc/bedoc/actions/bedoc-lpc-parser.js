/**
 * @file LPC parser for the gLPU simul_efun help generator.
 *
 * Extracts LPCDoc comment blocks and the function signatures that follow them
 * from LPC source files, producing the structured `functions` payload consumed
 * by the help formatter.
 *
 * This is adapted from the BeDoc sample LPC parser with Oxidus-specific
 * changes:
 *   - the signature regex captures the array `*` return marker,
 *   - blocks that are not attached to a function (file headers, documented
 *     variables) are dropped instead of crashing the run,
 *   - `private` functions are excluded (not part of the public API),
 *   - free-form `@errors` / `@throws` tags are captured.
 *
 * @author gesslar
 */

import {ActionBuilder, ACTIVITY} from "@gesslar/actioneer"
import {Collection, Data, Util} from "@gesslar/toolkit"

const {WHILE} = ACTIVITY

export default class LpcParser {
  static meta = Object.freeze({
    kind: "parser",
    input: "lpc",
    terms: "ref://./bedoc-lpc-parser.yaml"
  })

  setup = builder => builder
    .do("Extract blocks", this.#extractBlocks)
    .do("Process functions", ACTIVITY.SPLIT,
      ctx => ctx, // splitter
      ctx => ctx, // rejoiner
      new ActionBuilder()
        .do("Extract signature", this.#johnHandcock)
        .do("Extract description", this.#extractDescription)
        .do("Extract tags", WHILE, ctx => {
          return ctx.lines.length > 0
        }, this.#extractTag)
    )
    .done(this.#finally)

  async #extractBlocks(ctx) {
    ctx = Data.append(ctx, "\n")

    const result = []
    const lines = ctx.split("\n")

    while(lines.length) {
      const block = {}

      const startIndex = lines.findIndex(line => this.#regexes.get("block-start").exec(line))
      // The closing `*/` must come after this block's opening — otherwise a
      // plain `/* ... */` header comment earlier in the file would steal it
      // and abort the whole file.
      const endIndex = lines.findIndex((line, i) =>
        i > startIndex && this.#regexes.get("block-stop").exec(line))

      if(startIndex < 0 || endIndex <= startIndex)
        break

      block.lines = lines.slice(startIndex+1, endIndex)

      lines.splice(0, endIndex+1)

      const idIndex = lines.findIndex(line => this.#regexes.get("function").test(line))
      const nextBlockIndex = lines.findIndex(line => this.#regexes.get("block-start").test(line))

      if(idIndex > -1) {
        if(nextBlockIndex !== -1 && idIndex > nextBlockIndex) {
          // The next thing is another doc block, not a function — this block
          // documents a file header or a variable. Leave block.function unset;
          // #finally drops it.
          lines.splice(0, nextBlockIndex)
        } else {
          const func = this.#regexes.get("function").exec(lines[idIndex])
          block.function = func

          lines.splice(0, 1)
        }
      }

      result.push(block)
    }

    return result
  }

  #gimme = ob =>
    Object.fromEntries(Object.entries(ob).filter(([_, v]) => v != null))

  #johnHandcock = ctx => {
    const {function: func} = ctx
    const signature = this.#gimme(func?.groups ?? {})

    signature.array = signature.array ? true : false

    signature.parameters = signature.parms
      ? signature.parms.split(",").map(p => p.trim()).filter(Boolean)
      : []
    delete signature.parms

    return Object.assign(ctx, {signature})
  }

  #extractDescription = ctx => {
    const {lines} = ctx

    const comment = this.#regexes.get("comment-line")
    const tagId = this.#regexes.get("tag-id")

    const description = []
    Object.assign(ctx, {description})

    if(!(comment.test(lines.join("\n"))))
      return ctx

    while(lines.length > 0) {
      const line = lines.shift()

      if(!comment.test(line))
        continue

      if(tagId.test(line)) {
        lines.unshift(line)
        break
      }

      const {content} = comment.exec(line)?.groups ?? {}
      description.push(content ?? "")
    }

    return ctx
  }

  #extractTag = async ctx => {
    const {lines, tag: extractedTags = {}} = ctx

    const comment = this.#regexes.get("comment-line")
    const tagId = this.#regexes.get("tag-id")
    // narrower to broader
    const patterns = ["return", "example", "simple", "tag"].map(e => this.#regexes.get(e))

    const line = lines.shift()

    if(!comment.test(line))
      return ctx

    if(!tagId.test(line))
      return ctx

    const pattern = patterns.find(e => e.test(line))

    if(!pattern)
      return ctx

    const {groups} = pattern.exec(line) ?? {}
    if(!groups)
      return ctx

    const {tag} = groups
    if(!tag)
      return ctx

    delete groups.tag
    if(groups.content)
      groups.content = [groups.content]
    else
      groups.content = []

    while(lines.length > 0) {
      const continued = lines.shift()

      if(tagId.test(continued)) {
        lines.unshift(continued)
        break
      }

      const {content} = comment.exec(continued)?.groups ?? {}

      groups.content.push(content ?? "")
    }

    const curr = extractedTags[tag] ?? []
    curr.push(groups)

    Object.assign(extractedTags, {[tag]: curr})

    return Object.assign(ctx, {tag: extractedTags})
  }

  async #finally(ctx) {
    // Keep only blocks attached to a non-private function. File headers and
    // documented variables have no function; private functions are not part of
    // the public API.
    const documented = ctx.filter(block =>
      block.function && block.signature?.access !== "private")

    const functions = await Collection.asyncMap(documented, async func => {
      const result = {
        name: func.function.groups.name,
        description: func.description,
        signature: func.signature,
      }

      const tags = func.tag ?? {}

      if(tags.param)
        result.param = tags.param
          .map(({type, name, content}) => ({type, name, content}))

      if(tags.return || tags.returns) {
        const ret = (tags.return ?? tags.returns)[0]
        result.return = {type: ret.type, content: ret.content}
      }

      if(tags.errors || tags.throws) {
        const errs = [...(tags.errors ?? []), ...(tags.throws ?? [])]
        result.errors = errs.flatMap(({content}) => content)
      }

      if(tags.example || tags.examples) {
        const examples = tags.example ?? tags.examples
        result.example = examples.flatMap(({content}) => content)
      }

      return result
    })

    return {functions}
  }

  #regexes = new Map([
    ["block-start", /^\s*\/\*\*.*$/],
    ["block-stop", /^\s*\*\/\s*$/],
    ["comment-line", /^\s\*((?:\s)(?<content>[\s\S]+))?/],
    ["tag-id", /^\s\*\s@[a-zA-Z]/],
    ["tag", Util.regexify(`
      ^\\s*\\*(\\s
      @(?<tag>\\w+)\\s*
      \\{(?<type>\\w+(?:\\|\\w+)*(?:\\*)?)\\}\\s+
      (?<name>(\\w+(\\.\\w?)*=?\\w*\\s*(?<rest>\\.{3})?|\\[\\w+=?.*]))(?:\\s+-)?\\s+|\\s)
      (?<content>[\\s\\S]+?)
      $
    `
    )],
    ["simple", /^\s*\*\s*@(?<tag>errors|throws)\b\s*(?:-\s+)?(?<content>.*)$/],
    ["return", /^\s*\*\s*@(?<tag>returns?)\s+\{(?<type>[^}]*)\}(?:\s+(?:-\s+)?(?<content>.*))?/],
    ["example", /^\s\* @(?<tag>examples?)((?:\s)(?<content>[\s\S]+))?/],
    ["function", Util.regexify(`
      ^\\s*
      (?<access>public|protected|private)?
      \\s*
      (?<modifier1>nomask|varargs)?
      \\s*
      (?<modifier2>nomask|varargs)?
      \\s*
      (?<type>(int|float|void|string|object|mixed|mapping|array|buffer|function))\\s*(?<array>\\*)?
      \\s*
      (?<name>[a-zA-Z_][a-zA-Z0-9_]*)
      \\s*
      \\((?<parms>.*)\\)
      \\s*
      \\{?.*
      `
    )]
  ])
}
