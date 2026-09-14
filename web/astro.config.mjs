// @ts-check
import { defineConfig } from 'astro/config';

// Fully static museum site. Python (scripts/gen_site_index.py) exports
// web/data/museum.json; Astro prerenders every HTML route from it so
// crawlers see real cards/copy with no client fetch required.
export default defineConfig({
  output: 'static',
  build: {
    format: 'directory',
  },
  vite: {
    server: {
      watch: {
        ignored: ['**/data/museum.json'],
      },
    },
  },
});
