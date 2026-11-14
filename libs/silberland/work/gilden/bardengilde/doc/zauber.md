# Bardenzauber
Grunsaetzlich sind alle Zauber der Barden Zauberlieder. Sie basieren auf einem
der beiden oder sogar den beiden Kernskills `Musizieren` und `Singen`.

## Lernen von Zaubern
siehe [Miniquests fuer Spells](./miniquests_fuer_spells.md)

## Zauberuebersicht

Zauber | GS | Typus | Kurzbeschreibung
|------|----|-------|------------------|
| Das gelueftete Geheimnis | 1 | Utility | klassischer 'identifiziere' |
| Schrei des Verderbens | 1 | Angriff | Einfacher Angriffszauber auf einen Gegner mit DT_SOUND |
| Der Dinge wahrer Hintergrund | 2 | Utility | klassisches `schaetz` |
| Ode an die Sterne | 2 | Utility | Erschafft Licht, in dem ein Stern beschworen wird (oder Dunkelheit fuer Dunkelelfen)
| Kampfzauber 1 | 3 | Angriff | Vorbereiteter Zauber, gibt dem Barden einen gestapelten, auslösbaren Angriff a la Elementarpfeil |
| Lied der Zauber | 3 | Staerkung | Verstärkt die Wirkung (SA_DAMAGE/SA_DURATION/SA_EXTENSION) anderer Zauber, sie kosten dafür mehr |
| Schildlied | 4 | Schutz | Schild, der Schaden absorbiert bis er aufgebraucht ist |
| Ein Ton in der Stille | 4 | Heilung | Heilt Taunheit er Zuhoerer, benoetigt eine Stimmgabel
| Lied der Winde | Utility | 5 | Analog zu `lokalisiere` der Paladine
| Reparaturlied | 5 | Objekt | Repariert Ausruestung der Zuhoerer
| Reiselied | 6 | Reise | Keine/Weniger Erschöpfung beim Reisen, Schutz vor hoher/niedriger Temperatur, Unterwasseratmung, Fliegen, … also gegenereller Schutz vor Umwelteinflüssen |
| Regenerationslied | 6 | Heilung | Solange der Barde spielt Heilen alle  im Raum regelmäßig LP, ab GS 7 werden Hunger/Durst geheilt |
| Spaehlied | 7 | Reise | Erlaubt Raeume auszukundschafte, ohne dort wirklich hinzugehen |
| Handwerkslied | 7 | Staerkung | So lange der Barde spielt erhalten Zuhoerer einen Bonus auf Skills
| Alptraumlied | 7 | Illusion | Holt eine Alptraumkreatur aus den Träumen eines Gegners (nur Lebewesen), das diesen einen Gegner angreift
| Magieschutz | 8 | Schutz | Gibt eine Chance Zauber abzuwehren
| Passiver Kampfzauber | 8 | Angriff | Umhüllt den Barden mit einer Aura, die seinen Feinden regelmäßig schadet (analog alkoholfahne der zechis) |
| Heldenlied | 9 | Staerkung | Klassischer Buff a la "Gottsegen", allerdings fokussiert auf ein Attri (nach Richtung des Barden) und geringer LP/MP bonus
| Giftlied | 9 | Heilung | So lange der Barde spielt reduziert sich die Giftstufe aller Zuhörer regelmäßig um 1, sowie Alkohol wird vermindert |
| Schlaflied | 9 | Beeinflussung | Macht Gegner langsamer bzw. laesst sie sogar ein paar Runden aussetzen, bei kritischem Erfolg
| Illusionaere Umgebung | 10 | Illusion | Der Barde veraendert den Raum, in dem er sich befindet, wodurch der Gegner laufend Debuggs erhaelt. Je laenger der Barde im Raum steht, desto staerker
| Massenschutz | 11 | Schutz | Schutzzauber fuer mehrere Ziele, wirkt staerker, wenn mehr "Geschuetzte" im Raum sind
| Kampfunterbrechung | 11 | Illusion | Unterbricht den Kampf kurz, wie "Fluch der Mumie" |
| Massenangriff | 12 | Angriff | Schaden bei allen Feinden im Raum analog zu Sturmflut/Erdbeben/... |
| Erneuerung der Gestalt | 12 | Heilung | So lange der Barde spielt werden koerperliche Gebrechen (Frosch, Geist, Paralyse, Blindheit, Taubheit) per Zufall geheilt |
| Verzauberung | 13 | Objekt | Verzaubert einen Gegenstand (Waffe/Ruestung), damit sie einem Spieler Boni (Angriff, Ruestung, ...) gibt (ITEMD wiederverwenden?) |
| Freundschaftslied | 13 | Beeinflussung | Bezaubert einen NPC und macht ihn zum Kampfgefaehrten |
| Teleportlied | 14 | Reise | Teleportiert den Barden an verschiedene Orte mit kurzer Sequenz (zB bekannte Sehertore, Hauptstädte, …)
| Friedenslied* | 15 | Beeinflussung | So lange der Barde spielt kann im Raum nicht gekämpft werden 
| Lied der Lieder* | 15 | Staerkung | So lange der Barde spielt akkumuliert er Inspiration, die Inspiration kann über das Maximum hinaus gehen und wird auch länger gehalten |

* nur eines der beiden Lieder kann auf GS 15 erlernt werden