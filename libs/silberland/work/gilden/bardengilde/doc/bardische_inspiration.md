# Bardische Inspiration

Die bardische Inspiration ist eine weitere Sonderfertigkeit der Barden. Je mehr Musik der Barde macht,
desto inspirierter wird er und erlangt dadurch zusaetzliche Boni. Bardische Inspiration entsteht durch
das spielen von Zauberliedern, und die effekte sind entweder passiv (abhaengig von der Inspirationsstufe)
oder werden zufaellig beim Musizieren oder Singen ausgeloest.

## Inspiration Generieren
Bei jedem Zauber erhaelt der Barde `success / 1000` Inspirationspunkte dazu (P_BARD_INSPIRATION). Bei negativem
Sucess wird entsprechend abgebaut.

Die Inspirationsstufe (IS) entspricht immer: `ln(P_BARD_INSPIRATION)` oder in LPC: `log(bard->QueryProp(P_BARD_INSPIRATION))`.
Je mehr Inspration gesammelt wurde, desto laenger dauert es also die naechst Stufe zu erhalten. Die hoechste Stufe ist 5.

Pro Minute, die der Barde keine Inspiration aufbaut (`P_BARD_LAST_INSPIRED > 60`) baut er `IS^2` Punkte ab. Je mehr Punkte er
also hat, desto mehr baut er ab.

Damit ergeben sich eine logrithmische Kurve zum aufbau der Inspirationsstufen, sowie eine expotentielle im Abbau. Es is
also schwer die Stufen entsprechend aufzubauen und zu halten. Oder anders rum: Es ist ein exponentieller Aufwand notwendig,
um die Stufe zu aufzubauen oder zu halten.

## Talente umlernen
Alle 28 Tage kann ein Barde seine Talentslots zuruecksetzen und neue Talente aktivieren. Das Zuruecksetzen kostet 
neben der zeitlichen Limitierung zusaetzlich 50.000 Erfahrungspunkte.

## Generelle Auswirkungen

### Zufaellig ausgeloeste Effekte
* Naechster Zauber des Barden wird automatisch kritisch (success > MAX_ABILITY)

Chance auf einen der generellen Effekte steigt mit der Inspirationsstufe (+5% pro Stufe). Effekt werden
beim Anwenden der Skills 'Muszieren' oder 'Singen' ausgeloest.

### Passive Effekte
* Zauber werden geringfuegig billiger (1% pro Inspirationsstufe)

## Inspirationstalente
Der Barde waehlt alle 4 Gildenstufen (+1 fuer GS 15) ein Inspirationstalent. Dieses modifiziert
die bardische Inspiration und fuegt Effekte hinzu.

### Inspirationsschuebe
Jedes dieser Talente fuegt den Zufallseffekten einen weiteren hinzu.

| Talent                   | Auswirkung                                                                               | Alpha |
|--------------------------|------------------------------------------------------------------------------------------|-------|
| Allegro                  | Verbündert erhaelt IS Runden mehr Angriffe                                               | x
| Ermutigende Worte        | Kleine SP- und HP-Heilung (5*Inspirationsstufe) fuer alle Mitspieler im Raum             | x
| Kreativer Schub          | Befeuert die Kreativitaet eines Verbuendeten (+ IS*10 SA_DAMAGE fuer ein paar Runden)    | 
| Heldenhafte Ausstrahlung | Verbuendete im Raum erhalten kurzfristig (IS * 10 Sekunden) +1 auf ein Attribut          |
| Stakkato                 | Die "Zauberpause" aller Verbuendeten im Raum wird zurueckgesetzt                         | x 
| Faszinierende Vorstellung| Gegner im Raum sind fuer einen Moment fasziniert und setzen aus (max. IS Runden)         | x

### Passive Talente
Passive Talente wirken so lange der Barde mindestens eine Stufe Inspiration hat, und werden mit jeder
Stufe staerker.
 
| Talent             |Auswirkung                                                                                     | Alpha
|--------------------|------------------------------------------------------------------------------------------------|-----
| Crescendo          | Pro IS gibt es +0.5% Bonus auf Erfolg                                                          | x
| Tambourmajor       | +1% Bonus pro IS auf alle drei Angriffszauber                                                  | x
| Heilsame Klaenge   | Bonuswirkung bei Heilzaubern (Regernationslied, Giftlied, Erneuerung, Taubheitslied)             | 
| Angenehme Stimme   | Bonuserfolg aus 'Singen' zaehlt um 1% pro IS mehr                                              | x
| Flinke Finger      | Bonuserfolg aus 'Musizieren' zaehlt um 1% mehr pro IS                                          | x
| Bannsaenger        | +1% Bonus pro IS auf alle Schutzzauber (Schildlieder, Entzaubern, Magiebannlied)               | x
| Landstreicher      | Verlängert die Wirkungsdauer der "Reiselieder" (Lichtlied, Reiselied, Spaehlied)               |
| Molto Adagio!      | Aufrechterhaltene Zauberlieder (zB Giftlied) werden laenger gespielt (=laengere Wirkungsdauer) |
| Forte, Fortissimo! | Lieder, die mehr als eine Person betreffen, betreffen mehr Personen nach IS                    | x
| Kanon              | Wenn der Barden ein Lied spielt, das bereits von einem anderen Barden wirkt, stapeln sich die Effekte |                                                                       |
| Alte Geschichten   | Abhaengig von der Bardengruppe verurschachen Zauber zusaetzliche Schadens/Schutzarten          | x
| Elfische Melodie   | Die Kostenerhoehung von 'Lied der Zauber' wrid halbiert.                                       | x
| Schrilles Echo        | Schrei des Verderbens schadet zeitverzoegert nochmal mit halber Staerke                                  |
| Versatiler Musiker | Der Barde kann nun jedes beliebige Musikinstrument verwenden und erleidete keine Abzuege bei  Verwendung eines Instruments, das nicht zu seiner Gruppe gehoert                               |
| Traumwandler       | Illusionslieder (Schatten im Traumland, Illusionaere Umgebung, Kampfunterbrechung - debuffs) +1% Bonus pro IS                       |
| Charmeur | +1% Bonus pro IS auf Beeinflussungen (Schlaflied, Freundschaftslied, Friedenslied) | |
| Quell der Inspiration | +1% Bonbus pro IS auf Staerkungen | x |

Kommt erst spaeter:
* Dirigent: Zauberlieder, die der Barde gemeinsam mit anderen Barden im Orchester spielt erhalten einen kleinen Bonus (IS in %)

#### Finale
Wird ein Finale angewendet werden alle IS verbraucht und fuer einige Zeit kann keine Inspiration generieren. 
Das erste Finale kann erst auf GS 12 erlernt werden. Pro reset kann nur ein Finale gespielt werden.

| Talent | Verbrauch | Auswirkung
:--------:-----------:-----------:
| Reinigendes Finale | alle IS | Heilt einen Statuseffekt pro IS bei einem zufaelligen Spieler im Raum
| Belebendes Finale | alle IS | Heilt 20 HP/MP pro IS bei allen Mitspielern im Raum
| Hallendes Finale | alle IS | die nächsten IS Zauber wirken mit 1/2 Staerke auf einen weiteren Gegner (oder den selbel doppelt)