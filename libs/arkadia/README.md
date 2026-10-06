# Arkadia

Polskojęzyczna lokalizacja/fork mudliba silnika Genesis (CD gamedriver), tego samego, na którym oparty jest już włączony do tej kolekcji `genesis` (oryginał angielski) -- pierwsza pozycja w tej kolekcji w języku innym niż chiński, angielski czy niemiecki. Standardowy fantastyczny świat w stylu silnika CD, z własnym, charakterystycznym dla tej lokalizacji wymogiem przy tworzeniu postaci: nowo przybyła dusza musi samodzielnie podać odmianę własnego imienia przez wszystkie 6 polskich przypadków (mianownik/dopełniacz/celownik/biernik/narzędnik/miejscownik), a standardowe angielskie komendy duszy zostały w pełni zastąpione polskimi odpowiednikami (`spojrz`/`sp`, `zakoncz`, `stan`, `nagraj`, `haslo`). Świeżo zarejestrowana postać trafia jako bezcielesny duch do kamiennej sali na planie półkola, otoczonej pięcioma milczącymi posągami trzymającymi płonące pochodnie, z tajemniczym portalem pośrodku -- dotknięcie posągu wybiera rasę (ogr, halfling, człowiek, krasnolud lub elf), a w sąsiedniej galerii o kopulastym sklepieniu bezwłosy rzeźbiarz pyta o płeć, wzrost, budowę i dwie cechy wyglądu, po czym lepi z gliny figurkę na twoje podobieństwo; po jej dotknięciu przyjmujesz jej postać, a przejście przez portal daje prawdziwe ciało i przenosi do lokalnej świątyni, w której zaczynają wszyscy nowi gracze. Źródło: <https://github.com/84rn/lpmud>.

## Ciekawostki

- Nowa postać musi samodzielnie podać odmianę własnego imienia przez
  wszystkie 6 polskich przypadków (mianownik/dopełniacz/celownik/biernik/
  narzędnik/miejscownik) -- to prawdziwa, zamierzona funkcja lokalizacji,
  nie błąd. Standardowe angielskie komendy duszy zostały w pełni zastąpione
  polskimi odpowiednikami (`spojrz`/`sp`, `zakoncz`, `stan`, `nagraj`,
  `haslo`).
- Archiwum jest w rzeczywistości czystym ASCII -- wszystkie polskie znaki
  diakrytyczne są zapisane bez ogonków w całym kodzie i tekście gry (nawet
  własna walidacja imion w kodzie gry dopuszcza tylko litery `a`-`z`).
- Naprawiono kilka poważnych, wcześniej nieujawnionych błędów w oryginalnym
  kodzie (nie związanych z portowaniem na FluffOS): niezainicjowane mapy
  globalne w `secure/master/fob.lpc` (dominująca przyczyna awarii "Value
  being indexed is zero"), błędny układ pól w makrze `DEFAULT_DOMAINS`
  (rozjeżdżający się z rzeczywistymi stałymi `FOB_DOM_*`), oraz pusty,
  nigdy nie skonfigurowany plik `syslog/KEEPERSAVE.o` z archiwum autora.
  Pełne szczegóły w `NOTES.md`.

## Konto administratora / Admin account

- id: `fluffos`, hasło: `Mud@2026x` (dokładne `Mud@2026` z zadania nie
  spełnia własnej polityki haseł tego mudliba -- musi zaczynać i kończyć
  się literą), ranga: `WIZ_KEEPER` (9, najwyższa w tym mudlibie).
- Zarejestrowane najpierw jako zwykły śmiertelnik, następnie dodane do
  `DEFAULT_WIZARDS`/`DEFAULT_DOMAINS` w `config/sys/local.h` (`new_character()`
  odrzuca rejestrację imienia już figurującego jako czarodziej). Postać jest
  już ucieleśniona (człowiek), więc po zalogowaniu działają komendy
  czarodzieja (`tree`, `ls`, `mbs`, `Dump`).

## Status

Czysty rozruch: wszystkie 92 pliki z listy preloadu ładują się poprawnie. Pełna
rejestracja nowej postaci, gra podstawowymi komendami oraz ponowne
logowanie po restarcie sterownika zweryfikowane end-to-end. Brak
jakichkolwiek wychodzących połączeń sieciowych. Pełne szczegóły w
`NOTES.md`.

WASM: zweryfikowano (`wasm_status`: `playable`). Pełna rejestracja przez
standardowy webowy terminal tego projektu (nazwa, hasło x2, odmiana
imienia przez 6 przypadków, e-mail) kończy się dokładnie tak samo jak na
natywnym sterowniku -- postać trafia do sali wyboru rasy i poprawnie
wykonuje `spojrz`/`stan`. Przy okazji znaleziono i naprawiono jeden
prawdziwy, ogólny błąd (nie specyficzny dla WASM): w drzewie `players/`
brakowało 24 z 26 katalogów na literę (zostały tylko `f/` i `r/`, jedyne
zawierające prawdziwe zapisy), przez co każda nowa postać o imieniu na
inną literę nie mogła się zapisać. Naprawiono, dodając puste znaczniki
`.gitkeep` do brakujących katalogów. Pełne szczegóły w `NOTES.md`, § 9.

## Uruchomienie lokalne

```
cd libs/arkadia
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port gry: **40244**.
