// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import starlightScrollToTop from 'starlight-scroll-to-top';
import starlightHeadingBadges from 'starlight-heading-badges';
// import starlightCodeblockFullscreen from 'starlight-codeblock-fullscreen';
import { ion } from 'starlight-ion-theme';
import { readFileSync } from 'node:fs';

const loadGrammar = (/** @type {string} */ file) => JSON.parse(
	readFileSync(new URL(`./src/grammars/${file}`, import.meta.url), 'utf-8')
);
const lpmlGrammar = loadGrammar('lpml.tmLanguage.json');
const lpcGrammar = loadGrammar('lpc.tmLanguage.json');

// https://astro.build/config
export default defineConfig({
	vite: {
		resolve: {
			preserveSymlinks: true,
		},
	},
	integrations: [
		starlight({
			plugins: [
				ion(),
				starlightScrollToTop(),
				starlightHeadingBadges(),
				// starlightCodeblockFullscreen(), // TODO: duplicate export default bug with scroll-to-top — https://github.com/frostybee/starlight-codeblock-fullscreen/issues/2
			],
			expressiveCode: {
				shiki: {
					langs: [lpmlGrammar, lpcGrammar],
				},
			},
			customCss: ['./src/styles/custom.css'],
			title: 'Oxidus',
			logo: {
				light: './src/assets/logo.svg',
				dark: './src/assets/logo.svg',
			},
			favicon: '/favicon.ico',
			social: [
				{ icon: 'github', label: 'GitHub', href: 'https://github.com/gesslar/oxidus-mudlib' },
				{ icon: 'discord', label: 'Discord', href: 'https://discord.gg/wzUbBgs3AQ' },
			],
			sidebar: [
				{
					label: 'Guides',
					autogenerate: { directory: 'guides' },
				},
				{
					label: 'Systems',
					autogenerate: { directory: 'systems' },
				},
				{
					label: 'Daemons',
					autogenerate: { directory: 'daemons' },
				},
			],
		}),
	],
});
