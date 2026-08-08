# 東方故事II v1.3b

一個 1994-2000 年間由 Annihilator 開發的台灣 ES2 血統 MUD（正體中
文），登入橫幅另稱「天朝帝國 / Celestial Empire」。

## 内容亮点

- 这是 1994-2000 年间由 Annihilator 开发的 ES II 引擎早期版本，地图
  内容只有一个"雪村"（`d/snow/`：广场、客栈、铁匠铺、集市、废墟等）
  —— 更接近 ES2 引擎本身附带的示范村，而不是一个完整实现的门派/江
  湖游戏，本轮见过的 `sjplgfjxb`/`sjplii` 等档案自称的"original
  from Lil, rewritten by Annihilator"血统就是从这里发端的。
- 登入横幅自称"天朝帝国 / Celestial Empire"，和内容里侠客门派主题
  几乎无关，更像是这个引擎当年在不同站点之间被反复重新命名、重新
  包装的一个样本。

## 注冊流程

英文使用者代號（3-12 個英文字母）→ 確認建立（y/n）→ 密碼（≥5 字
元）→ 確認密碼 → 電子郵件地址 → 種族（human 等）→ 性別（m/f）→ 中
文名字（1-6 個中文字）。

## 本次修復的關鍵 bug

- **編碼問題（本次最重要的發現）**：這份壓縮檔原本是 BIG5 編碼，但
  最初的自動轉換流程把它當成 GB18030 解碼——GB18030 幾乎涵蓋所有位
  元組序列，即使餵給它 BIG5 內容也「成功」解碼，只是產生完全的亂碼
  （落在注音符號 Unicode 區段的垃圾字元），而不是一個轉換流程可以攔
  截到的解碼錯誤。本次重新用 BIG5 對整個壓縮檔做了一次轉換（先用
  Python 對照 big5/gbk/gb18030/cp950 四種編碼試解碼原始 `.c` 檔，確
  認 BIG5 才是正確答案，再正式套用）。
- `adm/obj/master.lpc` 的 `connect(int port)` 用 `switch(port)` 比對
  一個寫死的 `MUD_PORT`（原始預設值 4000），但這個專案實際配置的埠
  號是 40144——不管在不在 WASM 下，每一個連線都會被拒絕（驅動記錄：
  `Can not accept connection ... due to error in connect()`）。已將
  `MUD_PORT` 巨集改為和 `config.fluffos` 一致。
- `adm/obj/master.lpc` 的 `valid_read`/`valid_write` 遞迴呼叫
  `load_object(SECURITY_D)` 卻沒有防遞迴機制——這個驅動禁止在編譯過
  程中呼叫 `load_object()`，第一次需要編譯 `securityd.lpc` 時就觸發
  「Too deep recursion」堆疊溢位。已加上防遞迴旗標（AGENTS.md 已收
  錄的標準修法）。
- `adm/daemons/userid.lpc`（identd/RFC1413 反查服務，純 socket 功
  能）在 WASM 下無法編譯；按慣例清空為 no-op。
- `is_chinese()` 沿用舊版 GBK 雙位元組假設（要求 `strlen>=2`），在這
  個驅動上 `strlen()` 按字元計算，導致任何單一字元或奇數字元長度的
  中文名字（例如三個字的名字）都會被誤判為「不是中文」。已改為
  Unicode 碼點區間判斷。
- 重新套用了一個先前已提交、但這次 BIG5 重新轉換（從 raw 重新產生
  work）不慎覆蓋掉的既有修復：移除和驅動自動預先定義的 `MUD_NAME` 衝
  突的 `#define MUD_NAME`（先查過 git 記錄確認那次提交只動過這一個檔
  案，再重新套用）。

## §10.7 深度功能測試修復的 bug（詳見 NOTES.md）

- **`feature/dbase.lpc` 的 `query()`/`query_temp()` 對多層
  `"exits/east"` 這類路徑永遠靜默傳回 `0`**（與 AGENTS.md §7.29 是同
  一種 bug）：`match_path()` 是 ACL 風格的「同層最長前綴比對」，不會
  像 `set()` 那樣遞迴鑽進巢狀 mapping。影響面極廣——玩家完全無法用
  `go`/方向指令移動房間，`apprentice` 拜師的兩段式確認也失效。已改
  成逐層遞迴查表。
- **`std/char.lpc` 的 `rank()`** 在沒有對應 `class` daemon（本檔案
  從未出貨任何 `daemon/class/*.lpc`）時，`call_other` 靜默傳回
  `int 0`，被 `score` 的 `%s` 格式化成字面 "0" 混進中文敘述句。已加
  `objectp()`/`function_exists()` 防護，退回既有的姓名式 `rank()`。
- **`data/chinese.o` 內嵌 13 處孤立反斜線**（原始 1994-2000 年代
  BIG5 檔案自帶的作者年代產物），導致整個中文翻譯詞典
  `restore_object()` 失敗，`to_chinese()` 全面失效（種族/性別等欄位
  顯示英文原文而非中文）。已用 `tr -d '\\'` 清除。
- **`config.fluffos` 的 `maximum evaluation cost : 700000`**（本專案
  模板預設值）在冷啟動後第一次登入時不夠用，觸發 eval-cost abort，
  角色被送進保底的 `/obj/void`。已按 AGENTS.md §7.90 提到
  `5000000`。

## 管理員帳號 / Admin account

- **id**: `fluffos`
- **密碼 / password**: `Mud@2026`
- **權限 / level**: `(admin)`

管理員名單存放在純文字檔 `adm/etc/wizlist` 裡（原始壓縮檔並未附帶此
檔案，本次新建）；帳號本身透過正常注冊流程建立。

> 警告：這是一個公開的預設密碼，僅供本地/瀏覽器試玩。正式對外開服前
> 請務必修改此密碼。

## 本地運行

```
cd libs/dfgsiiv13b
~/src/fluffos/build-debug/src/driver config.fluffos
```

遊戲埠號：**40144**。
