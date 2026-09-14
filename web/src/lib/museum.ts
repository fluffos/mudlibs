import { readFileSync, existsSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import path from 'node:path';

export type MuseumCard = {
  slug: string;
  status: string;
  name: string;
  desc: string;
  badge: string;
  icon: string;
  linked: boolean;
  search: string;
  meta_html: string;
};

export type MuseumCluster = {
  num: string;
  name: string;
  count_label: string;
  cards: MuseumCard[];
};

export type MuseumIndex = {
  lang: string;
  html_lang: string;
  og_locale: string;
  canonical_url: string;
  page_title: string;
  meta_desc: string;
  site_name: string;
  h1: string;
  intro_html: string;
  stats_html: string;
  footer_html: string;
  lang_switch_href: string;
  lang_switch_label: string;
  search_placeholder: string;
  filter_all: string;
  filter_playable: string;
  filter_limited: string;
  filter_noboot: string;
  n_total: number;
  n_play: number;
  n_lim: number;
  n_no: number;
  jsonld: string;
  crumb_html: string;
  engage_html: string;
  clusters: MuseumCluster[];
};

export type MuseumLibPage = {
  slug: string;
  page: 'landing' | 'info';
  canonical_url: string;
  page_title: string;
  meta_desc: string;
  h1: string;
  aka_html: string;
  crumb_html: string;
  jsonld: string;
  meta_html: string;
  upstream_html: string;
  desc_html: string;
  docs_html: string;
  engage_html: string;
  play_url: string;
  info_url: string;
  zip_url: string;
  cta_play: string;
  cta_info: string;
  cta_zip: string;
};

/** @deprecated alias — prefer MuseumLibPage */
export type MuseumLibPageAlias = MuseumLibPage;

export type MuseumData = {
  site_url: string;
  generated_at: string;
  indexes: Record<string, MuseumIndex>;
  index_aliases: { path: string; lang: string; canonical_url: string }[];
  libs: Record<string, { landing: MuseumLibPage; info: MuseumLibPage }>;
};

const dataPath = path.resolve(process.cwd(), 'data', 'museum.json');

let cached: MuseumData | null = null;

export function loadMuseum(): MuseumData {
  if (cached) return cached;
  if (!existsSync(dataPath)) {
    throw new Error(
      `Missing ${dataPath}. Run: python3 scripts/gen_site_index.py --export-astro-data first`,
    );
  }
  cached = JSON.parse(readFileSync(dataPath, 'utf8')) as MuseumData;
  return cached;
}
