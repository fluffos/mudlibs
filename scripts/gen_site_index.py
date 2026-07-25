#!/usr/bin/env python3
"""Generate the GitHub Pages index for the packed mudlib site.

Inputs (all inside this repo):
  TODO.md            per-lib rows; the "2026-07-23 rebuild+format+WASM pass:"
                     note in each row's Notes cell records the lib's WASM
                     status, from which we derive:
                       playable -- fully works end-to-end in the browser
                       limited  -- boots, but login is blocked/limited
                                   (reason kept alongside)
                       noboot   -- does not boot under WASM at all
  libs/<slug>/README.md  first heading = the game's Chinese name; first
                     paragraph of the 简介 section = 1-line description;
                     the 「## 管理员账号 / Admin account」 section = the
                     pre-seeded admin credentials (AGENTS.md §1.5: the
                     convention is fluffos / Mud@2026, but each lib's
                     README is authoritative -- a few document a variant
                     id, a passwordless login flow, or no seeded account
                     at all), shown on the card so visitors can log in
                     with wizard powers immediately.
  --commits FILE     optional lib-commits.json (slug -> {sha, date} of the
                     last commit that changed libs/<slug>, maintained by
                     scripts/update_lib_commits.py) -- rendered on each
                     card as a GitHub commit link plus a link to the
                     lib's source dir.  Omitted/missing entries just drop
                     that line from the card.

Outputs:
  scripts/wasm_status.json  the derived slug -> status mapping (build
                            artifact, so the parse is inspectable)
  <out>/index.html          the site index (default: site/index.html)

Usage: python3 scripts/gen_site_index.py [--out DIR] [--commits FILE]
"""

import argparse
import html
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
REPO_URL = "https://github.com/fluffos/mudlibs"

PASS_MARKER = "rebuild+format+WASM pass:"

# A lib is "playable" only when the pass note claims a verified full flow.
PLAYABLE_PATTERNS = [
    r"WASM fully works",
    r"full WASM playthrough confirmed",
    r"native\+WASM both clean",
    r"WASM works\b",
    r"playthrough both natively and under WASM",
    r"registration worked fully under WASM",
    r"clean both natively and under WASM",
    r"WASM plays essentially identically to native",
]
NOBOOT_PATTERN = r"WASM does NOT boot"


def parse_todo(todo_path):
    """Yield dicts for every per-lib row with Status == done."""
    rows = []
    for line in todo_path.read_text(encoding="utf-8").splitlines():
        if not line.startswith("| "):
            continue
        cells = [c.strip() for c in line.strip().strip("|").split("|")]
        # Notes cells may themselves contain '|' (e.g. a literal "||->&&"
        # code fix) -- rejoin everything past the 5th cell.
        if len(cells) < 6 or not cells[0].isdigit():
            continue
        num, archive, slug, port, status = cells[:5]
        notes = "|".join(cells[5:]).strip()
        if status != "done":
            continue
        if not slug:
            raise SystemExit(f"TODO.md row #{num}: done but no slug")
        rows.append(
            {"archive_num": int(num), "archive": archive, "slug": slug,
             "port": port, "notes": notes}
        )
    if not rows:
        raise SystemExit("no done rows parsed from TODO.md")
    return rows


def classify(slug, notes):
    """Return (status, wasm_note) derived from the WASM pass note."""
    if PASS_MARKER not in notes:
        raise SystemExit(
            f"lib {slug}: no '{PASS_MARKER}' note in its TODO.md row -- "
            "cannot derive a WASM status")
    seg = notes.rsplit(PASS_MARKER, 1)[1].strip()
    idx = seg.find("WASM")
    wasm_note = re.sub(r"\s+", " ", seg[idx:] if idx >= 0 else seg).strip()
    if re.search(NOBOOT_PATTERN, seg):
        return "noboot", wasm_note
    for pat in PLAYABLE_PATTERNS:
        if re.search(pat, seg):
            return "playable", wasm_note
    return "limited", wasm_note


def parse_readme(slug):
    """Return (name, description) from libs/<slug>/README.md."""
    path = REPO / "libs" / slug / "README.md"
    if not path.is_file():
        return slug, ""
    text = path.read_text(encoding="utf-8")
    m = re.search(r"^#\s+(.+)$", text, re.M)
    name = m.group(1).strip() if m else slug
    desc = ""
    m = re.search(r"^##\s*简介\s*$(.*?)(?=^#|\Z)", text, re.M | re.S)
    if m:
        for para in re.split(r"\n\s*\n", m.group(1).strip()):
            para = re.sub(r"\s+", " ", para.replace("\n", "")).strip()
            if para:
                desc = para
                break
    return name, desc


def parse_admin(slug):
    """Return (admin_id, password) from the README's
    「## 管理员账号 / Admin account」 section (the authoritative per-lib
    record -- see module docstring).  Parsed at render time straight from
    the README (like nothing is hardcoded for name/description either).
    password is "" when the section documents a passwordless login flow
    (rendered as 无密码), None when an id parsed but no password line did
    (rendered as 密码见 README); (None, None) when no seeded account is
    recorded (e.g. nitan170911, whose MySQL-backed registration blocked
    seeding) -- the card then shows no admin line at all.

    Formats in the wild (all matched):
      - **ID**：`fluffos`                    /  - **id**: `fluffos`
      - 账号 id：`fluffos`　密码：`Mud@2026`
      - **密码 / Password**：`Mud@2026`（...）；**管理密码(wizpwd)**：`Wiz@2026`
        (first 密码 match wins: the login password is always listed first)
      - **密码 / password**: 无 ——           (no password step at all)
    """
    path = REPO / "libs" / slug / "README.md"
    if not path.is_file():
        return None, None
    text = path.read_text(encoding="utf-8")
    m = re.search(r"^##\s*管理员账号\s*/\s*Admin account\s*$(.*?)(?=^##|\Z)",
                  text, re.M | re.S)
    if not m:
        return None, None
    sec = m.group(1)
    mid = re.search(r"(?:\bid\b|ID|账号 id)[^`\n]*[:：][^`\n]*`([^`]+)`",
                    sec, re.I)
    if not mid:
        return None, None
    mpw = re.search(r"(?:密码|password)[^`\n]*[:：][^`\n]*`([^`]+)`",
                    sec, re.I)
    if mpw:
        return mid.group(1), mpw.group(1)
    if re.search(r"(?:密码|password)[^\n`]*[:：]\s*无", sec):
        return mid.group(1), ""  # documented "no password step"
    return mid.group(1), None


def build_status(rows):
    libs = {}
    for row in rows:
        slug = row["slug"]
        status, wasm_note = classify(slug, row["notes"])
        name, desc = parse_readme(slug)
        libs[slug] = {
            "name": name,
            "status": status,
            "reason": wasm_note,
            "description": desc,
            "archive": row["archive"],
            "archive_num": row["archive_num"],
            "port": row["port"],
        }
    counts = {}
    for info in libs.values():
        counts[info["status"]] = counts.get(info["status"], 0) + 1
    return {"generated_from": "TODO.md", "counts": counts, "libs": libs}


BADGE = {
    "playable": ("✅", "可玩", "browser 内可完整游玩"),
    "limited": ("⚠️", "受限", "可启动,但登录受限或未完整验证"),
    "noboot": ("❌", "不可启动", "无法在 WASM 驱动下启动"),
}


def load_numbers():
    """slug -> sort key from scripts/lib_numbering.json's "NNN" / "NNN-M"
    number scheme, e.g. "043-1" -> (43, 1). Duplicate-archive entries
    (duplicate_of set) never own a libs/ dir and are skipped; the first
    real entry per slug wins. Unnumbered slugs sort after all numbered
    ones, alphabetically, rather than disappearing or crashing."""
    path = REPO / "scripts" / "lib_numbering.json"
    numbers = {}
    if path.is_file():
        data = json.loads(path.read_text(encoding="utf-8"))
        for e in data["libs"]:
            if e.get("duplicate_of") or e["slug"] in numbers:
                continue
            m = re.match(r"^(\d+)(?:-(\d+))?$", e["number"])
            if m:
                numbers[e["slug"]] = (int(m.group(1)), int(m.group(2) or 0))
    return numbers


def render_index(status, commits):
    libs = status["libs"]
    counts = status["counts"]
    numbers = load_numbers()
    entries = sorted(
        libs.items(),
        key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))

    # Cards contain inner links (commit / source / play), so they cannot be
    # <a> elements themselves (nested anchors are invalid HTML and browsers
    # split them apart).  Instead every card is a <div>; on linked cards the
    # title <a class="play"> is stretched over the whole card via ::after,
    # and the meta links sit above it with a higher z-index.
    cards = []
    for slug, info in entries:
        st = info["status"]
        icon, label, _ = BADGE[st]
        name = html.escape(info["name"])
        desc = html.escape(info["description"])
        reason = html.escape(info["reason"])
        linked = st != "noboot"
        title_html = (f'<a class="play" href="{slug}/">{name}</a>' if linked
                      else name)
        reason_html = ""
        if st != "playable":
            reason_html = f'<p class="reason" title="{reason}">{reason}</p>'

        meta_bits = []
        admin_id, admin_pw = parse_admin(slug)
        if admin_id:
            if admin_pw:
                cred = f"{admin_id} / {admin_pw}"
            elif admin_pw == "":
                cred = f"{admin_id}(无密码)"
            else:
                cred = f"{admin_id}(密码见 README)"
            meta_bits.append(
                '<span class="admin" title="内置管理员账号——用它登录即有'
                f'巫师权限">🔑 {html.escape(cred)}</span>')
        entry = commits.get(slug)
        if entry:
            short = html.escape(entry["sha"][:7])
            day = html.escape(entry.get("date", "")[:10])
            meta_bits.append(
                f'<span>更新 <a href="{REPO_URL}/commit/'
                f'{html.escape(entry["sha"])}" title="该游戏库最近一次改动的'
                f'提交">{short}</a> {day}</span>')
        meta_bits.append(
            f'<a href="{REPO_URL}/tree/main/libs/{html.escape(slug)}" '
            'title="该游戏库的源代码目录">源码</a>')
        meta_html = ('<p class="meta">' + "\n    ".join(meta_bits) + '</p>')

        cards.append(f"""<div class="card {st}{' linked' if linked else ''}">
  <div class="card-head">
    <h2>{title_html}</h2>
    <span class="badge {st}" title="{reason}">{icon} {label}</span>
  </div>
  <p class="slug">{html.escape(slug)}</p>
  <p class="desc">{desc}</p>
  {reason_html}
  {meta_html}
</div>""")

    n_total = len(libs)
    n_play = counts.get("playable", 0)
    n_lim = counts.get("limited", 0)
    n_no = counts.get("noboot", 0)
    cards_html = "\n".join(cards)

    return f"""<!doctype html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>中文 MUD 博物馆 — 浏览器直接游玩</title>
<style>
  :root {{
    --bg: #0b0e14; --fg: #d5dbe5; --dim: #6b7484; --accent: #7aa2f7;
    --panel: #11151f; --border: #232a38;
    --ok: #9ece6a; --warn: #e0af68; --bad: #f7768e;
  }}
  * {{ box-sizing: border-box; }}
  body {{
    margin: 0; background: var(--bg); color: var(--fg);
    font: 15px/1.6 -apple-system, "PingFang SC", "Microsoft YaHei",
          "Noto Sans CJK SC", sans-serif;
  }}
  .wrap {{ max-width: 1100px; margin: 0 auto; padding: 24px 16px 64px; }}
  h1 {{ font-size: 26px; margin: 8px 0 4px; color: var(--accent); }}
  .intro {{ color: var(--dim); margin: 0 0 6px; }}
  .stats {{ color: var(--dim); font-size: 13px; margin-bottom: 18px; }}
  .stats b {{ color: var(--fg); }}
  .controls {{
    display: flex; flex-wrap: wrap; gap: 8px; margin-bottom: 18px;
    position: sticky; top: 0; background: var(--bg); padding: 10px 0;
    z-index: 5; border-bottom: 1px solid var(--border);
  }}
  #q {{
    flex: 1 1 220px; background: var(--panel); border: 1px solid var(--border);
    border-radius: 8px; color: var(--fg); font: inherit; padding: 8px 12px;
    outline: none;
  }}
  #q:focus {{ border-color: var(--accent); }}
  .fbtn {{
    background: var(--panel); border: 1px solid var(--border); color: var(--fg);
    border-radius: 8px; padding: 8px 14px; font: inherit; font-size: 13px;
    cursor: pointer; white-space: nowrap;
  }}
  .fbtn.active {{ border-color: var(--accent); color: var(--accent); }}
  .grid {{
    display: grid; gap: 12px;
    grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  }}
  .card {{
    position: relative; display: block; background: var(--panel);
    border: 1px solid var(--border); border-radius: 10px; padding: 14px 16px;
    color: inherit; transition: border-color .15s;
  }}
  .card.linked:hover {{ border-color: var(--accent); }}
  .card .play {{ color: inherit; text-decoration: none; }}
  /* stretch the title link over the whole card (see render_index) */
  .card.linked .play::after {{ content: ""; position: absolute; inset: 0; }}
  .card.noboot {{ opacity: .55; }}
  .card-head {{ display: flex; align-items: baseline; gap: 8px;
               justify-content: space-between; }}
  .card h2 {{ font-size: 16px; margin: 0; }}
  .badge {{ font-size: 12px; white-space: nowrap; }}
  .badge.playable {{ color: var(--ok); }}
  .badge.limited {{ color: var(--warn); }}
  .badge.noboot {{ color: var(--bad); }}
  .slug {{ margin: 2px 0 6px; color: var(--dim); font-size: 12px;
          font-family: Consolas, Menlo, monospace; }}
  .desc {{
    margin: 0; font-size: 13px; color: var(--fg);
    display: -webkit-box; -webkit-line-clamp: 2; -webkit-box-orient: vertical;
    overflow: hidden;
  }}
  .reason {{
    margin: 8px 0 0; font-size: 12px; color: var(--warn);
    display: -webkit-box; -webkit-line-clamp: 2; -webkit-box-orient: vertical;
    overflow: hidden;
  }}
  .card.noboot .reason {{ color: var(--bad); }}
  .meta {{
    margin: 8px 0 0; font-size: 12px; color: var(--dim);
    display: flex; flex-wrap: wrap; gap: 2px 12px;
  }}
  .meta .admin {{ font-family: Consolas, Menlo, monospace; }}
  /* meta links must stay clickable above the stretched .play overlay */
  .meta a {{
    color: var(--accent); text-decoration: none;
    position: relative; z-index: 1;
  }}
  .meta a:hover {{ text-decoration: underline; }}
  footer {{ margin-top: 32px; color: var(--dim); font-size: 12px; }}
  footer a {{ color: var(--accent); }}
</style>
</head>
<body>
<div class="wrap">
  <h1>中文 MUD 博物馆</h1>
  <p class="intro">
    这里收藏了 {n_total} 个上世纪九十年代至今的中文 LPC MUD(泥潭)游戏库,
    均已修复并运行在 <a href="https://github.com/fluffos/fluffos"
    style="color:var(--accent)">FluffOS</a> 驱动上。整个驱动通过 WebAssembly
    在你的浏览器里运行 —— 点击任意一款游戏,即可像当年 telnet 泥潭一样注册、
    登录、行走江湖。无需安装,无需服务器。每张卡片还标注了预置的管理员账号
    (🔑)——用它登录即可获得巫师权限,自由探索游戏世界与代码。
  </p>
  <p class="stats">
    <b>{n_play}</b> 款可完整游玩(✅) ·
    <b>{n_lim}</b> 款可启动但登录受限(⚠️,多为依赖 query_ip_number()
    等浏览器环境缺失能力) · <b>{n_no}</b> 款暂无法启动(❌)
  </p>
  <div class="controls">
    <input id="q" type="search" placeholder="搜索游戏名 / slug ……"
           autocomplete="off">
    <button class="fbtn active" data-f="all">全部 {n_total}</button>
    <button class="fbtn" data-f="playable">✅ 可玩 {n_play}</button>
    <button class="fbtn" data-f="limited">⚠️ 受限 {n_lim}</button>
    <button class="fbtn" data-f="noboot">❌ 不可启动 {n_no}</button>
  </div>
  <div class="grid" id="grid">
{cards_html}
  </div>
  <footer>
    源代码与修复记录:<a href="https://github.com/fluffos/mudlibs">fluffos/mudlibs</a>
    · 驱动:<a href="https://github.com/fluffos/fluffos">FluffOS</a> (WebAssembly)
    · 游戏内容版权归原作者所有,仅作历史保存用途。
  </footer>
</div>
<script>
(function () {{
  var q = document.getElementById('q');
  var cards = Array.prototype.slice.call(
      document.querySelectorAll('#grid .card'));
  var btns = Array.prototype.slice.call(document.querySelectorAll('.fbtn'));
  var filter = 'all';
  function apply() {{
    var needle = q.value.trim().toLowerCase();
    cards.forEach(function (c) {{
      var okStatus = filter === 'all' || c.classList.contains(filter);
      var okText = !needle || c.textContent.toLowerCase().indexOf(needle) >= 0;
      c.style.display = okStatus && okText ? '' : 'none';
    }});
  }}
  q.addEventListener('input', apply);
  btns.forEach(function (b) {{
    b.addEventListener('click', function () {{
      btns.forEach(function (x) {{ x.classList.remove('active'); }});
      b.classList.add('active');
      filter = b.dataset.f;
      apply();
    }});
  }});
}})();
</script>
</body>
</html>
"""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(REPO / "site"),
                    help="output dir for index.html (default: site/)")
    ap.add_argument("--commits", default=None,
                    help="lib-commits.json from update_lib_commits.py "
                         "(slug -> last commit that changed the lib); "
                         "omit / missing file = render without that info")
    args = ap.parse_args()

    commits = {}
    if args.commits and Path(args.commits).is_file():
        commits = json.loads(
            Path(args.commits).read_text(encoding="utf-8")).get("libs", {})

    # TODO.md was retired (its content consolidated into README.md and
    # AGENTS.md); the checked-in scripts/wasm_status.json is now the
    # source of truth for per-lib WASM status. If TODO.md still exists
    # (historical checkout), re-derive and refresh the JSON from it;
    # otherwise read the JSON directly. Update the JSON by hand (or via
    # a future status-updating tool) when a lib's WASM status changes.
    status_path = REPO / "scripts" / "wasm_status.json"
    todo = REPO / "TODO.md"
    if todo.is_file():
        rows = parse_todo(todo)
        status = build_status(rows)
        status_path.write_text(
            json.dumps(status, ensure_ascii=False, indent=2, sort_keys=True) + "\n",
            encoding="utf-8")
    else:
        status = json.loads(status_path.read_text(encoding="utf-8"))

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "index.html").write_text(render_index(status, commits),
                                        encoding="utf-8")

    total = len(status["libs"])
    print(f"wasm_status.json: {total} libs -> {status['counts']}")
    print(f"index written to {out_dir / 'index.html'}")
    missing = [s for s in status["libs"]
               if not (REPO / "libs" / s / "config.fluffos").is_file()]
    if missing:
        print(f"warning: slugs without libs/<slug>/config.fluffos: {missing}",
              file=sys.stderr)


if __name__ == "__main__":
    main()
