/**
 * @file Help formatter for the gLPU simul_efun help generator.
 *
 * Turns each parsed function into a standalone `.help` document: an LPML
 * frontmatter block carrying the function name as the title, followed by a
 * body laid out like the driver efun docs under `/doc/driver/efun` — `### NAME`,
 * `### SYNOPSIS`, `### DESCRIPTION`, `### PARAMETERS`, `### RETURN VALUES`,
 * `### ERRORS`, and `### EXAMPLE` sections with four-space indented bodies.
 *
 * The complete per-function document is stashed on `ctx.formatted`; the
 * companion Format hook (doc/bedoc/hooks/sefun-help-hooks.js) writes each one
 * to its own file. The pipeline result itself is empty — this formatter emits
 * no combined output.
 *
 * @author gesslar
 */

import {ActionBuilder, ACTIVITY} from "@gesslar/actioneer"

const WIDTH = 76
const INDENT = 4

export default class HelpFormatter {
  static meta = Object.freeze({
    kind: "formatter",
    format: "help",
    extension: "help",
    terms: "ref://./bedoc-help-formatter.yaml"
  })

  setup = builder => builder
    .do("Format functions", ACTIVITY.SPLIT,
      ctx => ctx, // splitter
      ctx => ctx, // rejoiner — nothing to recombine; the hook writes each file
      new ActionBuilder()
        .do("Format function", this.#formatFunction)
    )
    .do("Finalize", this.#finalize)

  // -- Text helpers ---------------------------------------------------------

  // Word-wrap a single run of text to WIDTH columns, indenting every line.
  #wrap = (text, width, indent) => {
    const pad = " ".repeat(indent)
    const words = String(text).split(/\s+/).filter(Boolean)
    const lines = []
    let line = ""

    for(const word of words) {
      if(line && (pad + line + " " + word).length > width) {
        lines.push(pad + line)
        line = word
      } else {
        line = line ? line + " " + word : word
      }
    }

    if(line)
      lines.push(pad + line)

    return lines.join("\n")
  }

  // Collapse an array of raw comment lines into paragraphs, splitting on
  // blanks.
  #paragraphs = lines => {
    const paras = []
    let curr = []

    for(const line of (lines ?? [])) {
      if(line.trim() === "") {
        if(curr.length) {
          paras.push(curr.join(" "))
          curr = []
        }
      } else {
        curr.push(line.trim())
      }
    }

    if(curr.length)
      paras.push(curr.join(" "))

    return paras
  }

  #section = (heading, body) => `### ${heading}\n\n${body}`

  // -- Section builders -----------------------------------------------------

  #synopsis = signature => {
    const s = signature ?? {}
    const head = [s.access, s.modifier1, s.modifier2].filter(Boolean).join(" ")
    const params = s.parameters ?? []

    let sig = head ? head + " " : ""
    sig += s.type ?? "mixed"
    sig += s.array ? " *" : " "
    sig += s.name
    sig += params.length ? `( ${params.join(", ")} )` : "( void )"
    sig += ";"

    return sig
  }

  #parameters = params => {
    const rows = params.map(p => {
      let name = p.name
      let optional = false
      let defaultValue = null

      const optMatch = name.match(/^\[(.*)\]$/)
      if(optMatch) {
        optional = true
        name = optMatch[1]
      }

      const defMatch = name.match(/^([^=]*)=(.*)$/)
      if(defMatch) {
        name = defMatch[1]
        defaultValue = defMatch[2]
      }

      name = name.replace(/\.{3}/, "").trim()

      const type = Array.isArray(p.type) ? p.type.join("|") : p.type
      const bits = [type]
      if(optional)
        bits.push("optional")
      if(defaultValue != null && defaultValue !== "")
        bits.push(`default: ${defaultValue}`)

      const content = (p.content ?? [])
        .map(c => c.trim())
        .filter(Boolean)
        .join(" ")

      return {name, meta: `(${bits.join(", ")})`, content}
    })

    const col = Math.max(...rows.map(r => r.name.length), 1)
    const lines = []

    for(const row of rows) {
      lines.push(`${" ".repeat(INDENT)}${row.name.padEnd(col)}  ${row.meta}`)
      if(row.content)
        lines.push(this.#wrap(row.content, WIDTH, INDENT + col + 2))
      lines.push("")
    }

    while(lines.length && lines.at(-1) === "")
      lines.pop()

    return lines.join("\n")
  }

  #example = lines => {
    // Drop markdown code fences (``` / ```lang) — meaningless in a MUD help
    // display — and keep the code as-is.
    const body = [...(lines ?? [])].filter(line => !/^\s*```/.test(line))

    while(body.length && body.at(0).trim() === "")
      body.shift()
    while(body.length && body.at(-1).trim() === "")
      body.pop()

    const rendered = body.map(line =>
      line.trim() === "" ? "" : " ".repeat(INDENT) + line)

    // Dim the example code with {{di1}}…{{di0}} so it reads as de-emphasized.
    const first = rendered.findIndex(line => line !== "")
    if(first < 0)
      return ""

    let last = rendered.length - 1
    while(last > first && rendered[last] === "")
      last--

    rendered[first] = rendered[first].replace(/^( {4})/, "$1{{di1}}")
    rendered[last] += "{{di0}}"

    return rendered.join("\n")
  }

  // -- Pipeline -------------------------------------------------------------

  #formatFunction = ctx => {
    const sections = []
    const paragraphs = this.#paragraphs(ctx.description)
    const tagline = paragraphs[0] ?? ""

    // NAME
    const nameLine = `${ctx.name}()${tagline ? ` - ${tagline}` : ""}`
    sections.push(this.#section("NAME", this.#wrap(nameLine, WIDTH, INDENT)))

    // SYNOPSIS
    sections.push(this.#section("SYNOPSIS",
      `${" ".repeat(INDENT)}${this.#synopsis(ctx.signature)}`))

    // DESCRIPTION
    if(paragraphs.length) {
      const body = paragraphs.map(p => this.#wrap(p, WIDTH, INDENT)).join("\n\n")
      sections.push(this.#section("DESCRIPTION", body))
    }

    // PARAMETERS
    if(ctx.param?.length)
      sections.push(this.#section("PARAMETERS", this.#parameters(ctx.param)))

    // RETURN VALUES
    if(ctx.return && ctx.return.type !== "void") {
      const type = Array.isArray(ctx.return.type)
        ? ctx.return.type.join("|")
        : ctx.return.type
      const content = (ctx.return.content ?? []).map(c => c.trim()).filter(Boolean).join(" ")
      const body = this.#wrap(`(${type})${content ? ` ${content}` : ""}`, WIDTH, INDENT)
      sections.push(this.#section("RETURN VALUES", body))
    }

    // ERRORS
    if(ctx.errors?.length) {
      const text = ctx.errors.map(e => e.trim()).filter(Boolean).join(" ")
      if(text)
        sections.push(this.#section("ERRORS", this.#wrap(text, WIDTH, INDENT)))
    }

    // EXAMPLE
    if(ctx.example?.length) {
      const body = this.#example(ctx.example)
      if(body)
        sections.push(this.#section("EXAMPLE", body))
    }

    const frontmatter = `---\n{\n  title: ${JSON.stringify(ctx.name)}\n}\n---`
    const formatted = `${frontmatter}\n${sections.join("\n\n")}\n`

    // Mutate in place so the Format hook's after$formatFunction sees
    // `formatted` on the same context object.
    return Object.assign(ctx, {formatted})
  }

  // The per-function `.help` files are written by the Format hook. BeDoc still
  // writes one file per source module from this return value, so we hand back
  // the concatenated documents — the config routes that to a scratch
  // directory.
  #finalize = ctx =>
    Array.isArray(ctx)
      ? ctx.map(fn => fn.formatted).filter(Boolean).join("\n\n")
      : ""
}
