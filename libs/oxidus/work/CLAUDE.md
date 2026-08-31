@AGENTS.md

## Claude Code

The guide above is shared with every coding agent that works in this repository.
This section is the Claude-specific part.

- **Skills** live in [.claude/skills/](.claude/skills/) and are invoked by name
  with the Skill tool — `/lpc-coding-style`, `/lpcdoc`, `/lpc-review`, and the
  subsystem skills. The guide above lists which ones matter and when; reach for
  them through the tool rather than reading the `SKILL.md` files directly.
- **Reviewing** — any review pass, including `/code-review`, follows
  `/lpc-review`. The condensed rules under **Code Review Rules** above are the
  same standard, restated for reviewers that cannot invoke skills.
- **Verification** — `fluffos_validate` and the LPC language server's
  `lpc_diagnostics` are available over MCP, and are the compile-time sources of
  truth. They prove a file compiles, not that paths resolve or behaviour is
  correct; use `/mud-telnet` for anything behavioural.
