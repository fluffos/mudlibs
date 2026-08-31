/**
 * @file Format hook for the gLPU simul_efun help generator.
 *
 * BeDoc writes one output file per input source file, but each simul_efun
 * source holds many functions and we want one help file per function. This hook
 * intercepts each formatted function and writes it to its own
 * `<name>.help` file under `/doc/sefun`, all in a single flat directory (every
 * sefun is uniquely named). The formatter itself returns no combined output, so
 * these per-function writes are the only files produced.
 *
 * The output directory is resolved relative to this hook file, so it does not
 * depend on the working directory BeDoc is launched from.
 *
 * @author gesslar
 */

import {mkdir, writeFile} from "node:fs/promises"
import {dirname, join} from "node:path"
import {fileURLToPath} from "node:url"

const HERE = dirname(fileURLToPath(import.meta.url))
const OUTPUT_DIR = join(HERE, "..", "..", "sefun")

export class Format {
  setup = async() => {
    await mkdir(OUTPUT_DIR, {recursive: true})
  }

  after$formatFunction = async ctx => {
    if(!ctx?.name || !ctx?.formatted)
      return ctx

    await writeFile(join(OUTPUT_DIR, `${ctx.name}.help`), ctx.formatted)

    return ctx
  }
}
