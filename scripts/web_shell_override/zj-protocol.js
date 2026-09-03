// Adapter for the "指间MUD" (Zhijian MUD) mobile-client login protocol used
// by a small number of libs in this collection (zjdyzj, zjmudhell -- see
// each lib's README.md for the full writeup). Reverse-engineered and
// verified live against the real driver (scripts/wasm_client.js +
// Python's crypt module as an independent oracle) before being written:
//
//   1. Server sends "ver1.0,<hash>\r\n" where <hash> = crypt(ZJKEY, "zj")
//      (a fixed, non-random 13-char classic DES-crypt string: 2-char salt
//      + 11-char hash). No prior prompt.
//   2. Client must reply with crypt(ZJKEY, hash[2..3]) (salt = hash's own
//      3rd/4th characters). No ordinary telnet/web client can compute
//      this without a working DES-crypt(3) implementation.
//   3. On success: "版本验证成功\r\n\r\n", then (with NO further prompt
//      text at all) the server is waiting for one line:
//      "<id>║<password>║<crypt(ZJKEY,id)+crypt(ZJKEY,password)>║<email>"
//      (the checksum is keyed on the driver's own ZJKEY, not the
//      account's real password -- see logind.lpc's own security note:
//      this protocol does not verify a returning account's old password
//      at all, it just overwrites it).
//   4. Response is one of: an ESC + digit-code error (message text
//      follows some codes, e.g. "\x1b015<text>"; re-send the line from
//      step 3), "\x1b...0008" (brand new account: one more line needed,
//      "<gender m/f>║<avatar number>║<nickname>"), or "\x1b...0007"
//      (logged in, world is loading -- everything after this is normal
//      gameplay text, not this protocol).
//
// This file replaces steps 2 and 3-4's raw pipe-delimited input with an
// ordinary-looking sequence of prompts through the SAME #cmd input bar
// every other lib uses, computing the required crypt() calls via the
// bridge each affected lib's own logind.lpc exports with
// js_export("zj_crypt", ...) -- see that file's create(). Never a
// from-scratch DES-crypt reimplementation: the driver's own crypt() is
// the only thing that can guarantee byte-identical results to what it
// will itself validate.
(function () {
  const ENABLED = !!(window.FLUFFOS_ZIP_BOOT && window.FLUFFOS_ZIP_BOOT.zjProtocol);
  if (!ENABLED) return;

  async function zjCrypt(input) {
    return fluffos.callLPC('zj_crypt', input);
  }

  // ESC (0x1b) directly followed by digits is this protocol's own
  // in-band status-code marker (see zjmud.h) -- never a real ANSI escape,
  // which is always ESC + '[' first. Safe to strip everywhere, not just
  // during login: matching only on a bare digit run right after ESC can't
  // collide with a real CSI sequence.
  const CODE_RE = /\x1b(\d+)([^\x1b]*)/;

  // makeSession() isn't defined yet when this script runs (it's a function
  // declaration inside the main inline script, later in the document) --
  // so this can't wrap it the way tab-lock.js wraps createFluffOS (already
  // defined by the time that file loads). Instead index.html calls this
  // explicit extension point itself, once per session, right after
  // creating one -- see makeSession()'s own last line.
  window.installSessionAdapter = function (s) {
    installZjAdapter(s);
  };

  function installZjAdapter(s) {
    // 'challenge' | 'postchallenge' | 'collect' (id/pw/confirm/email) |
    // 'postregister' | 'char' (gender/avatar/name) | 'passthrough'
    let state = 'challenge';
    let buf = '';
    let fields = {};   // collected answers for the current 'collect'/'char' round
    let step = 0;      // index into the current round's prompt list

    const COLLECT_PROMPTS = [
      { key: 'id', prompt: '您的英文账号名 (English account ID)：', mask: false },
      { key: 'password', prompt: '您的密码 (password)：', mask: true },
      { key: 'password2', prompt: '请再输入一次密码以确认 (confirm password)：', mask: true },
      { key: 'email', prompt: '您的 Email（用于找回密码）：', mask: false },
    ];
    const CHAR_PROMPTS = [
      { key: 'gender', prompt: '角色性别，男(m)或女(f)：', mask: false },
      { key: 'avatar', prompt: '选择一个头像编号 (avatar number)：', mask: false },
      { key: 'name', prompt: '角色昵称 (nickname)：', mask: false },
    ];

    function setMasked(on) {
      cmdWrap.classList.toggle('masked', on);
      renderCmd();
    }

    function showPrompt(list) {
      const p = list[step];
      s.term.write('\r\n' + p.prompt);
      setMasked(!!p.mask);
    }

    function startCollect() {
      state = 'collect';
      fields = {};
      step = 0;
      showPrompt(COLLECT_PROMPTS);
    }

    function startChar() {
      state = 'char';
      fields = {};
      step = 0;
      showPrompt(CHAR_PROMPTS);
    }

    async function finishCollect() {
      // Set BEFORE the crypto bridge's await, not after: the bridge call
      // resolves on the driver's next tick (real, if small, latency), and
      // leaving `state` at 'collect' across that gap let a line typed in
      // that window get treated as one more round of the same prompt
      // sequence -- reachable in practice (verified live), not just
      // theoretical, since a fast typist or a scripted client can easily
      // send the next line before a tick has passed.
      state = 'sending';
      setMasked(false);
      if (fields.password !== fields.password2) {
        s.term.write('\r\n两次输入的密码不一致，请重新输入。\r\n');
        startCollect();
        return;
      }
      const [idHash, pwHash] = await Promise.all([
        zjCrypt(fields.id), zjCrypt(fields.password),
      ]);
      state = 'postregister';
      s.sendData(Array.from(utf8enc.encode(
        [fields.id, fields.password, idHash + pwHash, fields.email].join('║') + '\r\n')));
    }

    function finishChar() {
      // NOT 'passthrough' yet: the server still has to send its own
      // "0000007" acknowledgement (get_char() always succeeds once the
      // fields are well-formed -- no error/retry path exists here, unlike
      // get_user()) before entering the world. Wait for it and strip it
      // the same way postregister's 0007 branch does, or it leaks through
      // raw via the passthrough path instead.
      state = 'postchar';
      s.sendData(Array.from(utf8enc.encode(
        [fields.gender, fields.avatar, fields.name].join('║') + '\r\n')));
    }

    // Returns true if this line was consumed locally (never reaches the
    // real connection) -- see the s.lineFilter hook added to the main
    // Enter-key handler.
    s.lineFilter = (line) => {
      if (state === 'collect' || state === 'char') {
        const list = state === 'collect' ? COLLECT_PROMPTS : CHAR_PROMPTS;
        // Echo what was typed into the scrollback, same convention the
        // real (non-adapter) path uses -- except for a masked (password)
        // field, which stays out of the scrollback entirely, same reason
        // a real telnet password prompt suppresses it.
        if (!list[step].mask) s.term.write(line + '\r\n');
        fields[list[step].key] = line;
        step++;
        if (step < list.length) showPrompt(list);
        else if (state === 'collect') finishCollect();
        else finishChar();
        return true;
      }
      // 'sending': the composite line is being (or about to be) computed
      // and sent -- the driver isn't expecting anything from us yet, so
      // swallow rather than forward (matches 'collect'/'char': never
      // silently fall through to a raw send mid-adapter).
      if (state === 'sending') return true;
      return false;
    };

    function handleLine(line) {
      if (state === 'challenge') {
        const m = /^ver1\.0,(.+)$/.exec(line);
        if (!m) { s.term.write(line + '\r\n'); return; }
        state = 'postchallenge';
        const salt = m[1].slice(2, 4);
        zjCrypt(salt).then((resp) => {
          // At least one lib in this family (shujian3) has its challenge
          // validation entirely disabled server-side: "版本验证成功"
          // fires unconditionally, arriving in the SAME buffered batch as
          // "ver1.0,..." and processed synchronously by this same
          // handleLine loop before this promise callback ever runs --
          // moving state on to 'collect' (or beyond) already. Sending
          // this response late would land as get_user()'s first line
          // instead of a real id/password/checksum/email line (verified
          // live: produces its generic "sizeof(myinfo) != 4" error).
          // Only send while still genuinely waiting for it.
          if (state !== 'postchallenge') return;
          s.sendData(Array.from(utf8enc.encode(resp + '\r\n')));
        }).catch((e) => {
          console.error('zj-protocol: crypt bridge failed', e);
          s.term.write('\r\n[zj-protocol] 无法完成协议握手，请刷新页面重试。\r\n');
        });
        return;
      }
      if (state === 'postchallenge') {
        if (line.indexOf('版本验证成功') >= 0) {
          startCollect();
        } else {
          // "客户端非法" or anything else unexpected -- the driver has
          // already closed the connection at this point (see logind.lpc's
          // jiance()); show what it said rather than hang silently.
          s.term.write(line + '\r\n');
        }
        return;
      }
      if (state === 'postregister') {
        const m = CODE_RE.exec(line);
        if (m && m[1].endsWith('0007')) {
          state = 'passthrough';
          if (m[2]) s.term.write(m[2] + '\r\n');
          return;
        }
        if (m && m[1].endsWith('0008')) {
          startChar();
          return;
        }
        if (m) {
          // A validation error (illegal id, checksum mismatch, an
          // existing account's own save-file problem, ...) -- show the
          // message and restart the collection round, mirroring the
          // server's own input_to("get_user", ob) retry.
          s.term.write('\r\n' + m[2] + '\r\n');
          startCollect();
          return;
        }
        s.term.write(line + '\r\n');
        return;
      }
      if (state === 'postchar') {
        const m = CODE_RE.exec(line);
        if (m && m[1].endsWith('0007')) {
          state = 'passthrough';
          if (m[2]) s.term.write(m[2] + '\r\n');
          return;
        }
        if (m) {
          // A validation error (illegal/wrong-length nickname, ...) --
          // get_char() retries via input_to("get_char", ob) the same way
          // get_user() does; mirror that here too rather than leaving the
          // adapter stuck expecting a 0007 that will never come until the
          // player answers again.
          s.term.write('\r\n' + m[2] + '\r\n');
          startChar();
          return;
        }
        s.term.write(line + '\r\n');
        return;
      }
      s.term.write(line + '\r\n');
    }

    // Regular gameplay (see zjmud.h) still wraps specific UI elements --
    // exit lists, NPC/object interaction hints, room titles -- in the
    // same ESC+digit-code framing as the login messages, plus its own
    // "$zj#"/"$z2#"/"$br#" separators for the original mobile client to
    // split on. Ordinary room/combat/chat text is NOT wrapped (plain
    // write() calls), so this is deliberately a light, stateless cleanup
    // of just those markers -- not a full parser -- applied per-chunk
    // since none of it needs line boundaries to strip correctly. Accepted
    // gap: a marker split exactly across two onText() chunks (ESC at the
    // end of one, digits at the start of the next) leaks through unstripped
    // -- rare in practice, and no worse than doing nothing here at all.
    function cleanupGameplayText(t) {
      return t
        .replace(/\x1b\d+/g, '')
        .replace(/\$zj#/g, ' | ')
        .replace(/\$z2#/g, ' / ')
        .replace(/\$br#/g, '\r\n');
    }

    function wrapOnText() {
      const real = s.telnet.onText;
      s.telnet.onText = (t) => {
        if (state === 'passthrough') { real(cleanupGameplayText(t)); return; }
        buf += t;
        let idx;
        while ((idx = buf.indexOf('\n')) >= 0) {
          let line = buf.slice(0, idx);
          buf = buf.slice(idx + 1);
          if (line.endsWith('\r')) line = line.slice(0, -1);
          handleLine(line);
        }
      };
    }

    const origSetupTelnet = s.setupTelnet;
    s.setupTelnet = function () {
      origSetupTelnet();
      state = 'challenge';
      buf = '';
      wrapOnText();
    };
    wrapOnText();   // cover the setupTelnet() that already ran inside makeSession()
  }
})();
