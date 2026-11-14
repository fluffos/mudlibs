# Instrumente und Zauber der Barden

## Fokus fuer Musizieren
Barden benoetigen zum Spielen ihrer Lieder Instrumente. Das Instrument dient
dabei sozusagen als Fokus, durch den Lieder, die mit SK_MUSIC gespielt werden,
kanalisiert werden.

Wird ein Instrument abgelegt, erloeschen sofort alle Zauberlieder des Barden,
die damit gespielt wurden.

## Qualitaet des Instruments
Zusaetzlich hat die Qualitaet des Instruments, ausgedrueckt durch P_INSTRUMENT_LEVEL,
entscheidenden Einfluss. Einerseits muss die Stufe des Instruments ausreichend hoch
fuer das Lied sein (`P_INSTRUMENT_LEVEL >= Stufe des Lieds/3`). Ist die Instrumentenstufe
zu niedrig, kostet das Lied um 10% pro fehlender Stufe mehr Magiepunkte, da es "erzwungen"
werden muss. Ist die Stufe hoeher als gefordert, sinken die Kosten fuer das Lied um
1% pro Stufenunterschied.

Weiters begrenzt das Instrument, wieviele Zusatzupunkte SK_MUSIC einbringen kann 
(`max. success = P_INSTRUMENT_LEVEL*2000`).

_Beispiel_:
Ein Barde mit einer Astrone (P_INSTRUMENT_LEVEL = 1) kann alle Lieder bis Gildenstufe
3 normal spielen. Ein Lied der Stufe 4, wie zum Beispiel 'Ein Ton in der Stille' kosten
ihn um 10% mehr. Ausserdem kann er maximal 2000 zusaetzliche Erfolgspunkte durch den 
Skill SK_MUSIC (analog zu SK_CASTING) sammeln.

## Bardenweg und Instrumente
Jede Richtung der Bardengilde hat unterschiedliche favorisierte Instrumente:

| Richtung | Instrumentenart    | Instrumententyp |
|----------|--------------------|-----------------|
| Alestra | Saiteninstrument    | IT_STRING       |
| Tirena  | Blasinstrumente     | IT_WIND         |
| Korriax | Rhythmusinstrumente | IT_DRUM         |
| Sarrian | Glasinstrumente     | IT_GLASS        |

Die Instrumentenstufe eines unpassenden Instruments wird um eine Stufe reduziert.

_Beispiel:_
Wenn ein Barde von Alestra mit einer Lanara spielt, zaehlt die Stufe nur als 2, 
statt als 3, wie fuer Barden von Tirena.

Zusaetzlich sind alle Lieder, die mit einem falschen Instrument gespielt werden um 5% teurer
und schwaecher.

