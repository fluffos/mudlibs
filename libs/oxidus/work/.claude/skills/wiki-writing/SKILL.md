---
name: wiki-writing
description: Guidelines for writing Oxidus wiki pages in Starlight (Markdown/MDX). Covers Canadian English spelling, file locations, frontmatter, code blocks, and available components.
---

# Wiki Writing Guide

The Oxidus wiki lives in `doc/wiki/` and is built with [Astro Starlight](https://starlight.astro.build/). Pages are Markdown (`.md`) or MDX (`.mdx`) files in `doc/wiki/src/content/docs/`.

## Canadian English

All wiki content MUST use Canadian English spelling. This is not just "colour" — it is a complete and consistent dialect. Key rules:

### -our (not -or)
colour, honour, favour, behaviour, neighbour, armour, labour, humour, vigour, savour, endeavour, harbour, rumour, valour, candour, fervour, glamour, parlour, rancour, splendour, tumour, vapour

### -re (not -er)
centre, metre, litre, fibre, theatre, sabre, sombre, lustre, manoeuvre, spectre, calibre, meagre, reconnoitre

### -ise / -ize
Both are acceptable in Canadian English, but prefer **-ize** for consistency:
organize, recognize, realize, customize, categorize, optimize, specialize, authorize

### -ce (not -se) for nouns
defence, offence, licence (noun), practice (noun)
But: license (verb), practise (verb), advise (verb)

### -lled / -lling (doubled L)
travelled, travelling, traveller, cancelled, cancelling, modelled, modelling, labelled, labelling, levelled, levelling, fuelled, fuelling, counselled, counselling, jewellery

### -ogue (not -og)
catalogue, dialogue, analogue, prologue, epilogue, monologue

### -ae- / -oe- (retained)
aesthetic (not esthetic), manoeuvre (not maneuver), paediatric (not pediatric)

### Other Canadian spellings
- **cheque** (not check, for payments)
- **grey** (not gray)
- **aluminium** (not aluminum)
- **storey** (not story, for building floors)
- **tyre** (not tire, for wheels)
- **kerb** (not curb, for road edge)
- **gaol** is accepted but **jail** is more common in Canada
- **programme** for a plan/schedule, **program** for software
- **towards**, **afterwards**, **forwards** (with -s)
- **amongst**, **whilst** — acceptable but **among**, **while** are equally Canadian
- **pyjamas** (not pajamas)
- **doughnut** (not donut)
- **draught** (not draft, for beer/airflow — but "draft" for documents)

### When in doubt
Canadian English generally follows British spelling for most words, with some American exceptions (e.g., -ize is preferred over -ise). When genuinely uncertain, prefer the British spelling.

## File Structure

```
doc/wiki/src/content/docs/
├── index.mdx              # Home/splash page
├── systems/
│   ├── index.md           # Systems overview
│   └── loot.md            # Loot system docs
└── <section>/
    └── <page>.md
```

## Frontmatter

Every page needs YAML frontmatter:

```yaml
---
title: Page Title
description: Brief description for SEO and link previews.
---
```

Optional fields:
- `template: splash` — hero layout (used on index)
- `sidebar: { order: 1 }` — control sidebar sort order
- `tableOfContents: false` — disable TOC

## Code Blocks

Use fenced code blocks with language identifiers:

````
```lpc
inherit STD_OBJECT;

void setup() {
  set_id("widget");
}
```
````

Available custom languages:
- **`lpc`** — full LPC highlighting (keywords, types, modifiers, efuns)
- **`lpml`** — LPML data file highlighting (spacey keys, includes, etc.)

Also use standard identifiers: `c`, `json`, `json5`, `yaml`, `bash`, `js`, etc.

### Code block features (Expressive Code)

Title/filename:
````
```lpc title="adm/daemons/loot.lpc"
// code here
```
````

Line highlighting:
````
```lpc {3-5}
// lines 3-5 will be highlighted
```
````

## Starlight Components (MDX only)

In `.mdx` files, import and use built-in components:

```mdx
import { Card, CardGrid, Tabs, TabItem, Aside } from '@astrojs/starlight/components';

<CardGrid>
  <Card title="Title" icon="rocket">
    Card content here.
  </Card>
</CardGrid>

<Tabs>
  <TabItem label="Tab One">Content one</TabItem>
  <TabItem label="Tab Two">Content two</TabItem>
</Tabs>

<Aside type="tip">Helpful tip here.</Aside>
<Aside type="caution">Be careful!</Aside>
<Aside type="danger">Don't do this!</Aside>
```

Also available via Markdown syntax:
```md
:::tip
Helpful tip here.
:::

:::caution
Be careful!
:::
```

## Links

```md
[Link to another page](/systems/loot/)
[External link](https://fluffos.info/)
[Link to section](#section-heading)
```

## Images

Place images in `doc/wiki/src/assets/` and import them:

```mdx
import myImage from '../../assets/screenshot.png';

<img src={myImage.src} alt="Description" />
```

Or place in `doc/wiki/public/` and reference directly:

```md
![Description](/images/screenshot.png)
```

## Tables

Standard Markdown tables:

```md
| Column 1 | Column 2 | Column 3 |
|---|---|---|
| data | data | data |
```

## Sidebar Configuration

The sidebar is configured in `doc/wiki/astro.config.mjs`. To add a new section:

```js
sidebar: [
  {
    label: 'Section Name',
    autogenerate: { directory: 'section-name' },
  },
],
```

Or with manual entries:

```js
{
  label: 'Section Name',
  items: [
    { label: 'Page Title', slug: 'section/page' },
  ],
},
```
