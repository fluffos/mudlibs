
mudlib/sys/armour.h:
--------------------
P_AC                           "ac"                          
 *  Numerischer Wert fuer die Abwehrstaerke der Ruestung.

P_WORN                         "worn"                        
 *  Enthaelt, wenn die Ruestung getragen ist, das Objekt des Spielers/NPCs,
 *  der die Ruestung traegt, sonst 0.

P_ARMOUR_TYPE                  "armour_type"                 
 *  String fuer Art der Ruestung; welcher Koerperteil wird
 *  geschuetzt?

P_TEMPERATURE_PROTECTION       "temp_prot"                   
 *  Numerischer Wert, der den Temperaturschutz eines Ruestungsteils
 *  angibt. Positive Werte ergeben einen Schutz gegen Kaelte, negative
 *  Schutz gegen Hitze. Fuer die einzelnen Ruestungsarten werden Default-
 *  werte gesetzt.


mudlib/sys/container.h:
-----------------------
P_MAX_WEIGHT                   "max_weight"                  
 *  Maximales Gewicht in Gramm, das in dem Container verstaut werden
 *  kann.

P_CONTENTS                     "contents"                    
 *  Obsolet?

P_CNT_STATUS                   "cnt_status"                  
 *  Status des Containers (offen, geschlossen, abgeschlossen)
 *  siehe auch /sys/container.h

P_CNT_KEY                      "cnt_key"                     
 *  Signalisiert, wenn gesetzt, dass der Container einen Schluessel
 *  zum Oeffnen und/oder Schliessen benoetigt. Der Inhalt der Property
 *  kann frei gesetzt werden.
 *  Beispiel in /obj/container.c (Property definiert in /sys/container.h)

P_TRANSPARENT                  "transparent"                 
 *  ist != 0, wenn hinein oder hinausgeschaut werden kann.


mudlib/sys/environment.h:
-------------------------
P_ENVIRONMENT                  "environment"                 
 *  Mapping, das die Umgebung (z.B. Raum) eines Spielers beschreibt.
 *  Hier steht z.B. die Raumtemperatur:
 *  SetProp( P_ENVIRONMENT, ([ ENV_TEMPERATURE : 20 ]) ) setzt die Raum-
 *  temperatur auf 20 Grad.


mudlib/sys/fishing.h:
---------------------
P_WATER                        "water"                       
 *   Nachzulesen in /sys/fishing.h

P_FISH                         "fish"                        
 *   Nachzulesen in /sys/fishing.h

P_LIQUID                       "w_max_wasserfuellmenge"      
 *   Nachzulesen in /sys/fishing.h

P_LONG_EMPTY                   "w_longdesc_empty"            
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_LONG_FULL                    "w_longdesc_full"             
 *   Nachzulesen in /sys/fishing.h


mudlib/sys/food.h:
------------------
P_FOOD_INFO                    "food_info"                   
 *  Enthaelt ein Mapping mit Eigenschaften das Nahrungsobjektes.
 *  Moegliche Keys sind F_HEAL = Heilung, F_SOAK = Saettigung, F_ALCOHOL =
 *  Alkoholgehalt und F_POISON = Giftlevel.


mudlib/sys/language.h:
----------------------
P_ARTICLE                      "article"                     
 *  Gibt an, ob in der Beschreibung ein Artikel ausgegeben werden soll
 *  oder nicht.

P_GENDER                       "gender"                      
 *  Grammatikalisches Geschlecht des Objektes:
 *  (Definiert in language.h) MALE, FEMALE oder NEUTER


mudlib/sys/living/attributes.h:
-------------------------------
P_ATTRIBUTES                   "attributes"                  
 *  Alist mit den Attributen des Wesens.

P_ATTRIBUTES_OFFSETS           "attributes_offsets"          
 *  Mapping mit Offsets, die zu den Attributen addiert werden (koennen auch
 *  negativ sein) - zB Rassenboni.

P_ATTRIBUTES_MODIFIER          "attributes_modifier"         
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_ABILITIES                    "abilities"                   
 *  Alist mit Sonderfaehigkeiten.


mudlib/sys/living/combat.h:
---------------------------
P_RESISTANCE                   "resistance"                  
 *  Array mit Angriffsarten, gegen die das Lebewesen teilweise
 *  resistent ist.

P_VULNERABILITY                "vulnerability"               
 *  Array mit Angriffsarten, gegen die das Lebewesen empfindlich
 *  ist.

P_TOTAL_AC                     "total_ac"                    
 *  Numerischer Wert der Abwehrstaerke des Wesens.

P_HANDS                        "hands"                       
 *  3-elem. Array
 *  1. Elem.: String mit der Meldung, wenn ohne Waffen angegriffen wird.
 *  2. Elem.: Weaponclass, wenn ohne Waffen angegriffen wird.
 *  3. Elem.: Angriffs-typ, default ist DT_BLUDGEON

P_MAX_HANDS                    "max_hands"                   
 *  Anzahl der Haende, die ein Wesen hat.

P_USED_HANDS                   "used_hands"                  
 *  Anzahl der Haende in Benutztung

P_ATTACK_BUSY                  "attack_busy"                 
 *  Testet, ob ein Lebewesen (speziell ein Spieler) gerade einen Spell
 *  casten kann (abhaengig von P_LEVEL). 


mudlib/sys/living/life.h:
-------------------------
P_AGE                          "age"                         
 *  Alter des Spielers in Heart-Beats (1 HB == 2 Sekunden)

P_ALIGN                        "align"                       
 *  Numerischer Wert fuer Gut- oder Boesheit des Wesens.

P_DEADS                        "deads"                       
 *  Anzahl der Tode des Spielers seit Einfuehrung dieser Property (irgendwann
 *  im Dezember 94)

P_GHOST                        "ghost"                       
 *  Gesetzt, wenn der Spieler tot ist.

P_FROG                         "frog"                        
 *  Gesetzt, wenn der Spieler ein Frosch ist.

P_FOOD                         "food"                        
 *  Numerischer Wert fuer Saettigungsgrad des Wesens.

P_MAX_FOOD                     "max_food"                    
 *  Numerischer Wert fuer die maximale Saettigung des Wesens.

P_DRINK                        "drink"                       
 *  Numerischer Wert fuer Saettigung des Wesens mit Getraenken.

P_MAX_DRINK                    "max_drink"                   
 *  Numerischer Wert fuer die maximale 'Wassermenge' im Wesen.

P_ALCOHOL                      "alcohol"                     
 *  Num. Wert fuer Besoffenheit.

P_MAX_ALCOHOL                  "max_alcohol"                 
 *  Numerischer Wert fuer die Alkoholvertraeglichkeit des Wesens.

P_HP                           "hp"                          
 *  Anzahl der Lebenspunkte des Wesens.

P_MAX_HP                       "max_hp"                      
 *  Maximale Anzahl der Lebenspunkte.

P_SP                           "sp"                          
 *  Anzahl der Magiepunkte des Wesens.

P_MAX_SP                       "max_sp"                      
 *  Maximale Anzahl der Magiepunkte.

P_XP                           "xp"                          
 *  Anzahl der Erfahrungspunkte.

P_TEMPERATURE_RANGE            "temp_range"                  
 *  Temperaturbereich, in dem sich ein Spieler 'wohl fuehlt'.
 *  Fuer Menschen z.B. ([T_RANGE_MIN:5,T_RANGE_MAX:25]), d.h. 5-25 Grad
 *  Wenn Raumtemperatur+Temperaturschutz+Temperaturoffset nicht
 *  innerhalb dieses Bereichs liegen, sollen sich Auswirkungen auf
 *  den Spieler ergeben.

P_TEMPERATURE_OFFSET           "temp_offset"                 
 *  Offset auf den Temperaturschutz eines Spielers. Kann z.B. durch
 *  ein waermendes Getraenk o.ae. gesetzt werden.

P_TOTAL_TEMPERATURE_PROTECTION "tot_tprot"                   
 *  Gesamt-Temperaturschutz der Ruestung. Wird intern berechnet.


mudlib/sys/new_skills.h:
------------------------
P_VALID_GUILDS                 "valid_guilds"                
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_SKILLS                 "guild_skills"                
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_RESTRICTIONS           "guild_rest"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_DEFAULT_SPELLBOOK      "guild_sb"                    
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_MALE_TITLES            "guild_male_titles"           
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_FEMALE_TITLES          "guild_female_titles"         
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_LEVELS                 "guild_levels"                
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_SB_SPELLS                    "sb_spells"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GLOBAL_SKILLPROPS            "sm_global"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

#define                        P_GUILD                       
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_LEVEL                  "guild_level"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD_TITLE                  "guild_title"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NEWSKILLS                    "newskills"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NEXT_SPELL_TIME              "next_spell"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_TMP_ATTACK_HOOK              "attack_hook"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_TMP_DEFEND_HOOK              "defend_hook"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_DEFENDERS                    "defenders"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_SKILL_ATTRIBUTES             "skill_attr"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***


mudlib/sys/npc.h:
-----------------
P_NPC                          "is_npc"                      
 *  Gesetzt bei Monstern.


mudlib/sys/npc/chat.h:
----------------------
P_CHATS                        "chats"                       
 *  Alist mit Strings, die das Monster zufaellig ausgibt.

P_CHAT_CHANCE                  "chat_chance"                 
 *  Wahrscheinlichkeit, mit der die Chats ausgegeben werden.

P_ACHATS                       "achats"                      
 *  Chats, die das Monster im Kampf ausgibt.

P_ACHAT_CHANCE                 "achat_chance"                
 *  Wahrscheinlichkeit fuer die Attack-Chat-Ausgabe.


mudlib/sys/npc/combat.h:
------------------------
P_AGGRESSIVE                   "aggressive"                  
 *  Gesetzt, wenn das Wesen von sich aus Angriffe startet.

P_NOATTACK                     "noattack"                    
 *  P_NOATTACK im NPC gesetzt verhindert das ein Spieler den NPC
 *  angreifen kann. Setzen im Spieler nicht moeglich!
 *  Auch wenn ichs fast vergessen haette :-)   Gundur
 *  P_NOATTACK kann einen String enthalten, der an den Spieler ausgegeben
 *  wird, wenn er versucht, den NPC anzugreifen. Defaultmaessig wird
 *  " springt geschickt aus Deiner Reichweite." ausgegeben.

P_SPELLS                       "spells"                      
 *  NPC-Spells

P_SPELLRATE                    "spellrate"                   
 *  NPC-Spellrate (in %)

P_NPC_SPELL_VECTOR             "npc:rate_array"              
 *  Nur fuer internen Gebrauch!

P_NPC_HB_OFF_COUNT             "npc:beat_off_num"            
 *  Nur fuer internen Grbrauch!


mudlib/sys/npc/guard.h:
-----------------------
P_GUARD                        "guard"                       
 *  Gesetzt in NPCs, die nicht oder nicht ohne weiteres durch Spells
 *  aus dem Weg geraeumt werden sollen (durch Toeten schon).
 *  Siehe /sys/npc/guard.h


mudlib/sys/npc/info.h:
----------------------
P_LOG_INFO                     "log_info"                    
 *  Wenn diese Property gesetzt ist wird jede Frage, die ein
 *  Monster nicht beantworten kann, im Report-File des
 *  zustaendigen Magiers geloggt oder wahlweise in
 *  /log/loginfo/<dateiname> (wenn <dateiname> als Parameter
 *  angegeben wurde.

P_DEFAULT_INFO                 "default_info"                
 *  NPC-Info-System: Default-Antwort auf dumme Fragen


mudlib/sys/mnpc.h:
------------------
P_MNPC                         "is_mnpc"                      
 *  Gesetzt bei wandernden Monstern.

P_MNPC_AREA                    "mnpc_area"
 * Legt fest, in welchem Gebiet sich ein MNPC aufhalten darf. Ein String
 * wird als Gebiet interpretiert, dh. der MNPC darf in alle Raeume, die
 * mit dem String uebereinstimmen oder laenger sind (zB. "room/wegoben"
 * ist im Gebiet "room/weg" enthalten, nicht aber umgekehrt!). Es kann
 * auch ein String-Array angegeben werden, das dann als Menge von
 * erlaubten Gebieten interpretiert wird.

P_MNPC_CMDS                    "mnpc_cmds"
 * Dieses Array enthaelt eine Menge von Befehlen, die der MNPC Element
 * fuer Element ausfuehrt. Nach dem letzten Element faengt der MNPC wieder
 * mit Abarbeitung des ersten an. Hierbei gilt: Ist ein Element ein String,
 * so wird es per command() ausgefuehrt (z.B. "norden" oder "emote grinst."),
 * ist es eine Zahl, so wird entsprechend viele Sekunden lang gewartet bis
 * zum naechsten Befehl.
 * Damit der MNPC die Befehle ausfuehrt, muss zudem MOV_CMDS in
 * P_MNPC_FLAGS gesetzt sein.

P_MNPC_FLAGS                   "mnpc_flags"
 * Legt das Verhalten eines MNPCs durch diverse Flags fest:
 * MOV_BACKWARDS: 1: Der MNPC darf auch in den Raum zurueck, aus dem er
 *                   gekommen ist
 *                0: Der MNPC geht nur dann in den Raum zurueck, aus dem
 *                   er gekommen ist, wenn er in einer Sackgasse landet
 * MOV_INDOORS:  Der MNPC darf in geschlossene Raeume
 * MOV_OUTDOORS: Der MNPC darf ins Freie
 * MOV_SPECIAL:  Der MNPC darf special exits verwenden
 * MOV_MAYLOAD:  Der MNPC darf Raeume bei Bedarf laden. Dieses Flag
 *               sollte nach Moeglichkeit sparsam eingesetzt werden!
 * MOV_MOVES: aktiviert den MNPC, muss also gesetzt sein wenn er gehen soll
 * MOV_CMDS: zeigt an, dass der MNPC statt wandern die in P_MNPC_CMDS
 *           festgelegten Befehle ausfuehren soll. Ist sinnvoll, wenn man
 *           einen MNPC eine bestimmte Route gehen lassen will, in dem Fall
 *           sollte man aber achtgeben, dass er nicht zufaellig vom Weg
 *           abkommt (zB. per P_WIMPY !) und dann vollends verwirrt ist.

P_MNPC_WAIT                    "mnpc_wait"
 * Array von drei Zahlen. Die erste Zahl legt fest, wielange ein MNPC
 * warten soll, ehe er den ERSTEN Schritt macht, die zweite legt fest,
 * wielange er mindestens warten soll, ehe er jeden weiteren Schritt
 * macht, und die dritte wird bei jedem weiteren Schritt per random(zahl)
 * hinzuaddiert, um eine gewisse Zufaelligkeit zu ermoeglichen.

P_MNPC_DEFAULTROOM             "mnpc_defaultroom"
 * Legt den Default-Room eines MNPCs fest, in den dieser teleportiert
 * wird, wenn er sich hoffnungslos verirrt und keinen zulaessigen Weg
 * mehr heraus findet (oder gar wenn er kein Environment hat).


mudlib/sys/player.h:
--------------------
P_LAST_COMMAND_ENV             "last_command_env"            
 *  Der Raum, in dem das letzte Kommando eingegeben wurde.

P_HISTMIN                      "histmin"                     
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_SHOW_ALIAS_PROCESSING        "show_alias_processing"       
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_DEFAULT_NOTIFY_FAIL          "default_notify_fail"         
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NETDEAD_INFO                 "netdead_info"                
 *  Hier kann ein Raum Informationen in einem Spieler zwischenspeichern, wenn
 *  dieser in den Netztotenraum gemoved wird.

P_IP_NAME                      "ip_name"                     
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_AUTH_INFO                    "auth_info"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_LAST_KILLER                  "last_killer"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_ACTUAL_NOTIFY_FAIL           "actual_notify_fail"          
 *** KEINE BESCHREIBUNG VORHANDEN ***


mudlib/sys/player/base.h:
-------------------------
P_LAST_LOGIN                   "last_login"                  
 *  Zeitpunkt des letzen Logins

P_LAST_LOGOUT                  "last_logout"                 
 *  Zeitpunkt des letzen Logouts

P_IGNORE                       "ignore"                      
 *  Array der Spieler, deren Mitteilungen ignoriert werden.

P_SHOW_EXITS                   "show_exits"                  
 *  Gesetzt, wenn der Spieler die offensichtlichen Ausgaenge
 *  immer automatisch sehen will.

P_WANTS_TO_LEARN               "wants_to_learn"              
 *  Gesetzt, wenn der Magier die Filenamen sehen will.
 *  (Nur fuer Magier). Wird diese Property auf 0 gesetzt, gehen auch
 *  einige andere Dinge nicht mehr - verfolge zB. (und er ist 'toetbar')
 *  Eigentlich sollten dann auch die Magierbefehle wie "goto" usw
 *  unterbunden werden - das kommt vielleicht noch.

P_AUTOLOADOBJ                  "autoloadobj"                 
 *  Mit dieser Property werden Autoloadobjekte verwaltet.
 *  Der Inhalt der Property sind die permanenten Eigenschaften des
 *  Objektes, die der Spieler uebers ausloggen hinweg beibehaelt.
 *  Beim Einloggen werden sie automatisch neu gesetzt. (ACHTUNG:
 *  Die Property muss intern selbst verwaltet werden.)
 *  Autoloadobjekte werden beim Ausloggen nicht fallengelassen!

P_AUTOLOAD                     "autoload"                    
 *  Alist mit der Menge der Autoloadobjekte und den zugeh.
 *  Properties.

P_MAILADDR                     "mailaddr"                    
 *  EMailadresse des Spielers.

P_FOLLOW_SILENT                "follow_silent"               
 *  Wenn diese Property 1 ist, wird der MOVE vom verfolge Silent ausge-
 *  fuehrt.

P_INVIS                        "invis"                       
 *  Gesetzt, wenn der Spieler unsichtbar ist.
 *  Wird nicht zum Lesen benutzt. Ist nur bei Spielern und Monstern
 *  sinnvoll. Unsichtbare Objekte sollten SetProp(P_SHORT,0) gesetzt haben.

P_SECOND                       "second"                      
 *  Spieler ist Zweitie.
 *  Kann auch einen String enthalten mit dem Namen des Erstspielers.

P_TESTPLAYER                   "testplayer"                  
 *  Gesetzt, wenn der Spieler nicht in der Bestenliste auftauchen soll.
 *  Kann auch einen String enthalten mit dem Namen des Magiers.

P_TTY                          "tty"                         
 *  Name der Terminalemulation, die der Spieler nutzt.
 *  NOT YET IMPLEMENTED.

P_START_HOME                   "start_home"                  
 *  Raum, in dem der Spieler nach dem Einloggen landen soll

P_CMSG                         "clonemsg"                    
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_DMSG                         "destmsg"                     
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_CLONE_MSG                    "clone_msg"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_DESTRUCT_MSG                 "destruct_msg"                
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_CARRIED_VALUE                "carried"                     
 *  Entschaedigung, die der Spieler beim Einloggen erhaelt.

P_PROMPT                       "prompt"                      
 *  Das Prompt (Nur fuer Magier).

P_SCREENSIZE                   "screensize"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_FLAGS                        "can_flags"                   
 *  Flags des Spielers

P_CAN_FLAGS                    "can_flags"                   
 *  Flags, ob Spieler echoen/emoten kann == P_FLAGS

P_READ_NEWS                    "read_news"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NEEDED_QP                    "needed_qp"                   
 *  APs, die man fuer den Seherstatus braucht


mudlib/sys/player/can.h:
------------------------
P_CAN_FLAGS                    "can_flags"                   
 *  Flags, ob Spieler echoen/emoten kann == P_FLAGS


mudlib/sys/player/comm.h:
-------------------------
P_INTERMUD                     "intermud"                    
 *  Obsolet?

P_BUFFER                       "buffer"                      
 *  Enthaelt Kobold-Nachrichten

P_DEAF                         "deaf"                        
 *  Der Spieler ist taub.


mudlib/sys/player/description.h:
--------------------------------
P_EXTRA_LOOK                   "extralook"                   
 *  String, der einen zusaetzlichen Text in der long()-Beschreibung
 *  eines Spielers erzeugt.

P_PRESAY                       "presay"                      
 *  Presay des Spielers. Erscheint vor dem Namen in Kurz/Langbeschreibung.
 *  Erscheint auch in name(), also in sag, ruf, teile mit usw.

P_TITLE                        "title"                       
 *  Titel des Spielers. Erscheint hinter dem Namen in Kurz/Langbeschreibung.

P_CLASS                        "class"                       
 *  Im AL z.z. ohne Funktion

P_REFERENCE_OBJECT             "reference_object"
 * Das zuletzt vom Spieler untersuchte Objekt. Sinnvoll fuer Details
 * an Dingen, da zuerst nach Details an P_REFERENCE_OBJECT gesucht wird.


mudlib/sys/player/moving.h:
---------------------------
P_MSGIN                        "msgin"                       
 *  String mit der Meldung, die beim Verlassen eines Raumes mit M_GO
 *  an die uebrigen Anwesenden ausgegeben wird.

P_MSGOUT                       "msgout"                      
 *  String mit der Meldung, die beim Betreten eines Raumes mit M_GO
 *  an die uebrigen Anwesenden ausgegeben wird.

P_MMSGIN                       "mmsgin"                      
 *  String mit der Meldung, die beim Verlassen eines Raumes mit M_TPORT
 *  an die uebrigen Anwesenden ausgegeben wird.

P_MMSGOUT                      "mmsgout"                     
 *  String mit der Meldung, die beim Betreten eines Raumes mit M_TPORT
 *  an die uebrigen Anwesenden ausgegeben wird.


mudlib/sys/player/potion.h:
---------------------------
P_POTIONROOMS                  "potionrooms"                 
 *  Alist mit den Nummern der Raeume, in denen der Spieler noch Zauber-
 *  traenke finden kann.

P_TRANK_FINDEN                 "trank_finden"                
 *  Wenn die Property auf 1 steht kann immer ein Zaubertrank gefunden
 *  werden, auch wenn er nicht in der Liste des Spielers steht.


mudlib/sys/player/quest.h:
--------------------------
P_QUESTS                       "quests"                      
 *  Liste der geloesten Quests.

P_QP                           "questpoints"                 
 *  Anzahl der Questpunkte, die ein Spieler hat.


mudlib/sys/player/skills.h:
---------------------------
P_SKILLS                       "skills"                      
 *** KEINE BESCHREIBUNG VORHANDEN ***


mudlib/sys/player/viewcmd.h:
----------------------------
P_BLIND                        "blind"                       
 *  TRUE, wenn der Spieler nichts sehen kann.

P_BRIEF                        "brief"                       
 *  Ist gesetzt, wenn der Spieler nur die Kurzbeschreibung sehen will.
 *  Im 'Ultrakurzmodus' ist P_BRIEF auf 2 gesetzt.

P_SHORTINV                     "shortinv"                    
 *  Zeigt, wenn im Spieler gesetzt, alle Inventories im 'Kurzmodus' an,
 *  d.h. mehrfache Objekte werden nur einmal, dafuer aber mit der Anzahl
 *  in Klammern hinter dem Objektnamen, angezeigt.

P_COLUMN_MODE                  "column_mode"
 * Legt fuer einen Spieler fest, wie dieser die Anzeige seines Inventories
 * bzw. von Objekten in Raeumen haben will. 0 bedeutet keine spaltenweise
 * Anzeige, 1: Spalten, 2: automatisch, d.h. ab mehr als 6 Objekten wird
 * in Spalten angezeigt.


mudlib/sys/properties.h:
------------------------
P_KILLER                       "killer"                      
 *  Wird direkt beim Tod auf das toetende Objekt gesetzt

P_MURDER_MSG                   "murder_msg"                  
 *  Welche Meldung soll auf dem Moerder-Kanal erscheinen?

P_KILL_MSG                     "kill_msg"                    
 *  Meldung auf dem Todeskanal, wenn jemand von uns getoetet wird

P_KILL_NAME                    "kill_name"                   
 *  Name, der auf dem Todeskanal erscheint, wenn jemand von uns
 *  (z.B. auch ein Raum) getoetet wird

P_ENEMY_DEATH_SEQUENCE         "enemy_death_sequence"        
 *  Hiermit kann man die Todessequenz beeinflussen, die ein Spieler sieht.
 *  Steht hier ein Mapping, so sieht der Spieler die Standard-Sequenz,
 *  in der die durch die Keys indizierten Zeilen eingefuegt werden;
 *  steht hier ein Pointer (Array), so kann eine ganze Sequenz uebergeben
 *  werden, die der Spieler dann sieht (dazu sollte man vorher vielleicht
 *  /room/death/death_room.c konsultieren).

P_MSG_FLAGS                    "msg_flags"                   
 *  Der Inhalt dieser Property ist ein Mapping, in dem festgelegt wird, ob eine
 *  Ausgabe auf dem Todes- oder Moerderkanal normal, als 'emote' oder 'gemote'
 *  erfolgt. Der Key ist dabei entweder P_KILL_MSG oder P_MURDER_MSG, der Wert
 *  0 (normale Ausgabe), 1 (Ausgabe per 'emote') oder 2 (Ausgabe per 'gemote').
 *  Bsp: SetProp( P_MSG_FLAGS, ([P_KILL_MSG:1, P_MURDER_MSG:2]) )
 *  Anmerkung: Auf dem Todeskanal ist 'gemote' zur Zeit nicht moeglich.

P_CORPSE                       "corpse"                      
 *  Welchen Corpse hinterlassen wir?

P_CORPSE_FLAGS                 "corpse_flags"
 *  Diverse Flags beim Sterben eines Livings.
 *  COR_NOSETWEIGHT, COR_NOINVTRANSFER, COR_MSGIN, COR_KILLENEMY

P_CORPSE_PROPS                 "corpse_props"
 * Mapping, das diverse Properties enthaelt, die der Leiche nach ihrem
 * Clonen gesetzt werden.

P_LIGHT                        "light"                       
 *  Greift auf den Lichtlevel zu. Handle with care !!!

P_TOTAL_LIGHT                  "total_light"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_CLONER                       "cloner"                      
 *  Enthaelt einen String mit dem Namen desjenigen, der das Objekt gecloned hat.

P_LAST_CONTENT_CHANGE          "last_content_change"         
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_VALUE                        "value"                       
 *  Wert des Objektes in Goldmuenzen. Diesen Wert erhaelt man beim 
 *  Verkauf. Kaufen kostet ein Vielfaches hiervon.

P_FORCE_DEMONST                "force_demonst"               
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_INFO                         "info"                        
 *  Geheime Information, die ggf. ueber einen Zauberspruch
 *  von Spielern ermittelt werden kann.

P_READ_MSG                     "read_msg"                    
 *  Hier koennen Informationen gespeichert werden, die beim Lesen
 *  des Objektes ausgegeben werden.

P_FW_ALWAYS_READABLE           "fw_always_readable"          
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NOBUY                        "nobuy"                       
 *  Wenn diese Property gesetzt ist, wird das Objekt nach einem
 *  Verkauf im Laden zerstoert, damit es nicht wieder von einem Spieler
 *  gekauft werden kann.

P_NEVERDROP                    "neverdrop"                   
 *  Objekte mit dieser Property werden beim Tod des Spielers nicht
 *  in den Leichnam gelegt.
 *  P_NODROP wird automatisch mitgesetzt.

P_MAGIC                        "magic"                       
 *  Dieses Objekt ist magisch.

P_WEIGHT_PERCENT               "weight_percent"              
 *  Diese Property gibt an, wieviel Prozent des Gewichts des Inhaltes
 *  "nach aussen" wiedergegeben werden.

P_DOORS                        "doors"                       
 *  wird nicht(mehr) benutzt und fliegt demnaechst raus.

P_DOORS2                       "doors2"                      
 *  wird nicht(mehr) benutzt und fliegt demnaechst raus.

P_NO_TPORT                     "tport"                       
 *  Kann folgende Werte annnehmen (definiert in moving.h):
 *  NO_TPORT_IN  = Man kann nicht in den Raum hinein teleportieren.
 *  NO_TPORT_OUT = Man kann nicht aus dem Raum hinaus teleportieren.
 *  NO_TPORT     = Weder noch.

P_INDOORS                      "indoors"                     
 *  Gesetzt, wenn von dem Raum aus der Himmel nicht sichtbar ist.
 *  Dinge wie Wetter oder Mondaufgaenge werden in solchen Raeumen
 *  nicht gezeigt.

P_NOMAGIC                      "nomagic"                     
 *  Angabe in Prozent, mit welcher Wahrscheinlichkeit in einem
 *  Raum nicht gezaubert werden kann. Bei NPC's zeigt es die
 *  Resistenz gegen Magie an.

P_ORAKEL                       "orakel"                      
 *  Wenn diese Property gesetzt ist, kann das 'Orakel' (NPC, den
 *  man nach Quests befragt, im MG der 'alte Wanderer', im AL das
 *  'Burggespenst') in den Raum hinein.

P_RACE                         "race"                        
 *  String mit der Rasse des Wesens.

P_TOTAL_WC                     "total_wc"                    
 *  Numerischer Wert der Angriffsstaerke des Wesens.

P_ZAP_MSG                      "zap_msg"                     
 *  Dreielementiges Array:
 *  1.) Meldung, die der Magier beim Zappen bekommt.
 *  2.) Meldung, die die Spieler im Raum beim Zappen bekommen.
 *  3.) Meldung, die das Opfer beim Zappen bekommt.
 *  Mit @@wer@@, @@wessen@@, ... kann der Name des Opfers und mit
 *  @@ich@@ der Name des Magiers in die Meldung eingewebt werden.

P_AWAY                         "away"                        
 *  String der ausgegeben wird, wenn man weg ist und eine Mitteilung bekommt.

P_WEAPON                       "weapon"                      
 *  Momentan gezueckte Waffe.

P_ARMOURS                      "armours"                     
 *  Liste der getragenen Schutzbekleidungen.

P_COMBATCMDS                   "combatcmds"                  
 *  Fuer den Kampf gebrauchbare Befehle spezieller Objekte
 *  (damit auch Monster sie automatisch richtig anwenden koennen)
 *  Mapping ([ Befehl : Mapping ([ Eigenschaft: Wert]) ])
 *  Eigenschaften:
 *  C_MIN, C_AVG, C_MAX: Minimaler/durschschnittlicher/maximaler Schaden
 *  C_DTYPES: Damagetypes
 *  C_HEAL: Eigene Heilung

P_WIMPY                        "wimpy"                       
 *  Numerischer Wert. Das Wesen flieht, wenn die Lebenspunkte
 *  unter diesen Wert sinken.

P_WIMPY_DIRECTION              "wimpy_dir"                   
 *  Fluchtrichtung

P_HEAL                         "heal"                        
 *  Numerischer Wert, der beim Verzehr dieses Objektes zu den
 *  Lebenspunkten hinzugezaehlt wird. (kann auch negativ sein)
 *  Der Wert sollte zwischen +4 und -4 liegen und bei leichten
 *  Monstern 0 sein.

P_POISON                       "poison"                      
 *  Wie stark wir vergiftet sind (0..P_MAX_POISON)

P_MAX_POISON                   "max_poison"                  
 *  Maximal erreichbarer Giftlevel

P_DISABLE_ATTACK               "disable_attack"              
 *  Das Lebewesen kann nicht angreifen.

P_DIE_MSG                      "die_msg"                     
 *  String mit der Meldung, die ausgegeben wird, wenn das Wesen stirbt.
 *  ist die Property nicht gesetzt, so nehme " faellt tot zu Boden.\n".

P_KILLS                        "playerkills"                 
 *  Anzahl der Spieler, die dieser Spieler schon getoetet hat.
 *  Unerlaubte Manipulation ist ein SCHWERES VERGEHEN gegen
 *  die Mudreglen.

P_CALLED_FROM_IP               "called_from_ip"              
 *  Letzte IP-Adr, von der aus sich der Spieler eingeloggt hat.

P_DESCRIPTION                  "description"                 
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GUILD                        "guild"                       
 *  Gilde, der der Spieler angehoert.
 *  Ist 0, wenn der Spieler Abenteurer ist, ansonsten enthaelt
 *  die Propertie den Namen der Gilde (kleingeschrieben).

P_LEVEL                        "level"                       
 *  Spieler-Level (!= Magierlevel)

P_CAP_NAME                     "cap_name"                    
 *  Name des Spielers, der dekliniert und ausgegen wird.
 *  NOT YET IMPLEMENTED.

P_EARMUFFS                     "earmuffs"                    
 *  Shouts von Magiern mit Level < earmuffs werden abgeblockt
 *  (Nur fuer Magier)

P_MARRIED                      "married"                     
 *  Enthaelt einen String mit der uid des Partners
 *  (sofern vorhanden)

P_AMOUNT                       "amount"                      
 *  Anzahl der Objekte, fuer die das Objekt steht.

P_VALUE_PER_UNIT               "value_per_unit"              
 *  Wert in Goldstuecken pro Untereinheit.

P_WEIGHT_PER_UNIT              "weight_per_unit"             
 *  Gewicht in Gramm pro Untereinheit.

P_FUEL                         "fuel"                        
 *  Numerischer Wert fuer die Zeitdauer, die die Lichtquelle noch
 *  leuchten kann.

P_LIGHTDESC                    "lightdesc"                   
 *  String mit der Bezeichnung des Leuchtvorgangs, den die Licht-
 *  quelle ausfuehrt (leuchtend, brennend, gluehend ...)

P_DO_DESTRUCT                  "do_destruct"                 
 *  Flag, ob sich die Lichtquelle am Ende der Leuchtzeit selbst
 *  zerstoert. (Oder sogar mit String fuer die Meldung, die bei
 *  der Zerstoerung angegeben wird?)

P_LIGHTED                      "lighted"                     
 *  Flag, ob die Lichtquelle in Betrieb ist.

P_BODY                         "body"                        
 *  Numerischer Wert fuer die Abwehrstaerke des blanken Koerpers
 *  des Wesens.

P_HB                           "hb"                          
 *  Diese Property wird gesetzt, wenn das Monster immer einen
 *  heart_beat haben soll. (VORSICHT, nur wenn es WIRKLICH sein muss!)

P_NOAGGRESSIVE                 "noaggressive"                
 *  Wenn diese Property im Spieler gesetzt ist, wird er von NPC's, die
 *  P_AGGRESSIVE gesetzt haben, nicht angegriffen. Diese Property sollte
 *  nur im Rahmen eines Spells und nur kurzzeitig gesetzt sein.

P_ATTACK_ME                    "attack_me"                   
 *  z.z. unbenutzt

P_NOCORPSE                     "nocorpse"                    
 *  Gesetzt, wenn im Todesfall kein Leichnam erzeugt werden soll.

P_REJECT                       "reject"                      
 *  Ein Array aus 2 Elementen, das bestimmt, das der npc mit Dingen
 *  tuen soll, die ihm gegeben werden.
 *  Default, der npc behaelt die Dinge einfach.
 *  Wenn gesetzt:
 *  1.Element: Art der Handlung. (aus <moving.h>)
 *    REJECT_GIVE: Der NPC gibt das Objekt zurueck.
 *    REJECT_DROP: Der NPC laesst das Objekt fallen.
 *    REJECT_KEEP: Der NPC behaelt das Objekt doch.
 *  2.Arrayelement: Meldung, mit der der NPC die Handlung kommentiert.

P_RACE_DESCRIPTION             "racedescr"                   
 *  Beschreibung der Vor/Nachteile einer Rasse.

P_CONTAINER                    "container"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_FW_UNDERSTAND                "fw_understand"               
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_TRAY                         "tray"                        
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GIVEN_AMOUNT                 "u_ga"                        
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_GIVEN_OBJECT                 "u_go"                        
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_PURSUERS                     "pursuers"                    
 *  Enthaelt Verfolger - nicht von Hand manipulieren!

P_HP_HOOKS                     "hp_hooks"                    
 *  Welche Objekte sollen bei HP-Aenderungen benachrichtigt werden?

P_CURSED                       "cursed"                      
 *  Verfluchte Waffen/Ruestungen kann man nicht ausziehen/wegstecken

P_KEEP_ON_SELL                 "keep_on_sell"                
 *  Verhindert, wenn in einem Objekt gesetzt, den Verkauf des Objektes
 *  in einem Laden. Kann vom Spieler mit dem Befehl 'behalte' gesetzt
 *  werden.

P_NOSELL                       "nosell"                      
 *  Diese Property enthaelt eine Meldung, die ausgegeben wird, wenn
 *  jemand versucht, dieses Objekt zu verkaufen. Wird die Prop. auf einen
 *  nicht-String-Wert gesetzt, so wird eine Defaultmeldung ausgegeben.

P_SPECIAL_SHOP                 "special_shop"                
 *  Wird in Laeden (also Raeumen, die /std/laden inheriten) gesetzt, wenn
 *  nur bestimmte Objekte verkauft werden sollen. Enthaelt ein Mapping, das
 *  als Key die Property, die fuer zu verkaufende Objekte 'typisch' ist, enthaelt
 *  und als Value die Meldung, die ausgegeben wird, wenn der Laden andere Objekte
 *  ablehnt. 
 *  Also z.B. fuer einen Waffenladen ([P_WC:"Dies ist ein Waffenladen.\n"]).

P_INFORMME                     "informme"                    
 *  Informieren ueber Spieler, die ins Mud kommen/aus dem Mud gehen?

P_WAITFOR                      "waitfor"                     
 *  Die Erwarte-Liste

P_CLOCKMSG                     "clockmsg"                    
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_LOCALCMDS                    "localcmds"                   
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_PARA                         "para"                        
 *  Nummer der Parallelwelt in der ein Spieler ist.
 *  Wenn zu einem Raum room.c ein Raum room^1.c existiert, und der
 *  Spieler P_PARA auf 1 gesetzt hat, wird er statt in room.c in
 *  room^1.c gemoved.

P_SIZE                         "size"                        
 *  Groesse des Spielers oder NPCs in cm.


mudlib/sys/room/description.h:
------------------------------
P_INT_SHORT                    "int_short"                   
 *  Kurzbeschreibung, wenn man sich im Inneren des Containers
 *  befindet.

P_INT_LONG                     "int_long"                    
 *  Beschreibung, die man bekommt, wenn man sich in dem Container
 *  umschaut.

P_ROOM_MSG                     "room_msg"                    
 *  Liste mit Meldungen, die zufaellig im Raum ausgegeben werden.

P_FUNC_MSG                     "func_msg"                    
 *  Liste mit Funktionen, die zufaellig im Raum aufgerufen werden.

P_MSG_PROB                     "msg_prob"                    
 *  Numerischer Wert fuer Wahrscheinlichkeit, mit der die Meldungen
 *  und/oder die Funktionen ausgegeben/aufgerufen werden.

P_DETAILS                      "details"                     
 *  Diese Property enthaelt ein mapping, in der Objekt im Raum
 *  definiert werden und Beschreibungen, die ausgegeben werden,
 *  wenn man sich diese Details anschaut.

P_SPECIAL_DETAILS              "special_details"             
 *  Mapping von Details, die beim Anschauen eine Funktion starten.

P_READ_DETAILS                 "read_details"                
 *  Details, die durch Lesen ermittelt werden koennen.

P_SOUNDS                       "sounds"                      
 *  Enthaelt ein Mapping mit Geraeuschen im Raum und deren Beschreibungen. 
 *  Sollte niemals direkt manipuliert werden, sondern immer per AddSound
 *  und RemoveSound

P_SMELLS                       "smells"                      
 *  Enthaelt ein Mapping mit Geruechen im Raum und deren Beschreibungen. 
 *  Sollte niemals direkt manipuliert werden, sondern immer per AddSmell
 *  und RemoveSmell


mudlib/sys/room/doors.h:
------------------------
P_DOOR_INFOS                   "door_infos"                  
 *  Enthaelt ein Mapping mit Informationen ueber die Tueren im Raum.
 *  Sollte nie direkt manipuliert werden, sondern immer nur ueber die
 *  Funktionen des Doormasters (/obj/doormaster.c).
 *  Siehe dazu auch /sys/room/doors.h (frueher /sys/doorroom.h)


mudlib/sys/room/exits.h:
------------------------
P_EXITS                        "exits"                       
 *  Alist aller unmittelbar sichtbaren Ausgaenge mit zugehoerigen
 *  Nachbarraeumen. Sollte nur mittels AddExit() benutzt werden.

P_SPECIAL_EXITS                "special_exits"               
 *  Dito, aber anstatt des Nachbarraums wird eine Funktion (im Raum)
 *  angegebem, die bei Eingabe der Richtung ausgefuehrt wird.

P_EXIT_PREPOSITION             "exit_preposition"            
 *  Der Inhalt dieser Propery ist ein String, der bei 'non-standard' Ausgaengen
 *  (also solchen die nicht n,w,s,o,nw,no,sw,so,ob,u sind) vor den Ausgang davor-
 *  geschrieben wird. Wenn P_EXIT_PREPOSITION auf "nach" gesetzt ist erhalten
 *  die Spieler im Raum die Meldung 'Xyz geht nach rechts', wenn der Spieler Xyz
 *  den Raum durch den Ausgang 'rechts' verlaesst.


mudlib/sys/room/items.h:
------------------------
P_ITEMS                        "items"                       
 *  Definition von Gegenstaenden, die in dem Raum liegen sollen.
 *  Erklaerung in einem Extrafile.


mudlib/sys/shells.h:
--------------------
P_CURRENTDIR                   "currentdir"                  
 *  Momentanes Verzeichnis in dem der Spieler ist. (nur fuer
 *  Magier von Belang)

P_SHORT_CWD                    "short_cwd"                   
 *  .readme bei cd ausgeben oder nicht


mudlib/sys/snooping.h:
----------------------
P_SNOOPFLAGS                   "snoopflags"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***


mudlib/sys/thing/commands.h:
----------------------------
P_COMMANDS                     "commands"                    
 *  Enthaelt ein Mapping mit Kommandos, die ein Objekt oder
 *  Raum definiert. Sollte nur mittels AddCmd/RemoveCmd
 *  manipuliert werden.


mudlib/sys/thing/description.h:
-------------------------------
P_NAME                         "name"                        
 *  In dieser Property wird der Name des Objektes gespeichert. Er
 *  sollte nur aus einem Wort bestehen. Der Name dient dazu, das
 *  Objekt in einem Satz zu erwaehnen und wird auch dekliniert.

P_NAME_ADJ                     "name_adj"                    
 *  In dieser Property kann ein Adjektiv abgelegt werden, dass dann
 *  bei der Ausgabe mittels name() mitbenutzt wird.
 *  (In der Regel nicht noetig.)

P_SHORT                        "short"                       
 *  In dieser Property wird die Kurzbeschreibung des Objektes
 *  gespeichert, die beim Umschauen im Raum oder bei der Ausgabe
 *  des Inventars ausgegeben wird. Fuer unsichtbare Objekte
 *  sollte sie 0 sein.

P_LONG                         "long"                        
 *  Unter dieser Property wird die Beschreibung gespeichert, die
 *  bei der Untersuchung des Objektes ausgegeben wird.

P_IDS                          "ids"                         
 *  Hier werden die Bezeichnungen abgespeichert, unter denen sich das
 *  Objekt angesprochen fuehlt.
 *  Sollte nur mittels AddId( id ); gesetzt werden.

P_ADJECTIVES                   "adjectives"                  
 *  Hier werden Adjektive gespeichert, unter denen sich das Objekt
 *  angesprochen fuehlt. So sind Kombinationen der Synonyme mit
 *  mehreren Adjektiven moeglich. Ggf sollte auch der deklinierte
 *  Fall des Adjektives eingegeben werden.
 *  Sollte nur mittels AddAdjective( adjective ); gesetzt werden.

P_SHOW_INV                     "show_inv"                    
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_NO_INVIS                     "no_invis"                    
 *  P_NO_INVIS sollte in allen Gegenstaenden gesetzt werden, die Spieler nicht
 *  per Spell unsichtbar machen duerfen (die Spells sollten das natuerlich
 *  auch abfragen :). Fuer NPCs ist P_NO_INVIS per Default 1 fuer alle
 *  anderen Gegenstaende 0

P_SMELL                        "smell"
 * Der Geruch eines Objekts wird hier beschrieben, entweder als String,
 * oder als Mapping, dann wird die Rasse des an dem Objekt riechenden
 * Spielers als Index genommen.

P_SOUND                        "sound"
 * Das Geraeusch eines Objekts wird hier beschrieben, entweder als String,
 * oder als Mapping, dann wird die Rasse des an dem Objekt lauschenden
 * Spielers als Index genommen.


mudlib/sys/thing/language.h:
----------------------------
P_ARTICLE                      "article"                     
 *  Gibt an, ob in der Beschreibung ein Artikel ausgegeben werden soll
 *  oder nicht.

P_GENDER                       "gender"                      
 *  Grammatikalisches Geschlecht des Objektes:
 *  (Definiert in language.h) MALE, FEMALE oder NEUTER


mudlib/sys/thing/material.h:
----------------------------
P_MATERIAL                     "material"                    
 *  Material, aus dem ein Gegenstand besteht. Fuer normale Gegenstaende,
 *  Ruestungen und Waffen werden Defaultwerte gesetzt.


mudlib/sys/thing/moving.h:
--------------------------
P_NODROP                       "nodrop"                      
 *  Diese Property enthaelt eine Meldung, die ausgegeben wird, wenn
 *  jemand versucht, das Objekt fallen zu lassen. Wird die Prop.  auf einen 
 *  nicht-String-Wert gesetzt, so wird eine Defaultmeldung ausgegeben.

P_NOGET                        "noget"                       
 *  Diese Property enthaelt eine Meldung, die ausgegeben wird, wenn
 *  jemand versucht, dieses Objekt zu nehmen. Wird die Prop. auf einen
 *  nicht-String-Wert gesetzt, so wird eine Defaultmeldung ausgegeben.


mudlib/sys/thing/properties.h:
------------------------------
P_UID                          "uid"                         
 *  Simulation des Zugriffs auf die uid.

P_EUID                         "euid"                        
 *  Simulation des Zugriffs auf die euid.


mudlib/sys/thing/restrictions.h:
--------------------------------
P_WEIGHT                       "weight"                      
 *  Das Gewicht eines Objetes in Gramm.

P_TOTAL_WEIGHT                 "total_weight"                
 *  Gewicht incl. Inhalt in Gramm. P_WEIGHT_PERCENT wird beruecksichtigt.


mudlib/sys/transport.h:
-----------------------
P_ENTERMSG                     "entermsg"                    
 *  Array mit zwei Meldungen, eine fuer den Raum, den der Spieler
 *  verlaesst, und eine fuer den Transporter, in den er geht.

P_LEAVEMSG                     "leavemsg"                    
 *  Array mit zwei Meldungen, eine fuer den Transporter, den er verlaesst,
 *  und eine fuer den Raum in den er kommt.

P_LEAVEFAIL                    "leavefail"                   
 *  Meldung an ein Wesen, wenn es ausserhalb der Anlegezeiten den Transporter
 *  verlassen will. Ist die Prop. ein Array, so wird das erste Element als
 *  meldung an das Wesen, das zweite als Meldung an die Mitspieler im
 *  Transporter geschickt.

P_ENTERFAIL                    "enterfail"                   
 *  Meldung an ein Wesen, wenn den vollen Transporter betreten will.
 *  Ist die Prop. ein Array, so wird das erste Element als
 *  meldung an das Wesen, das zweite als Meldung an die Mitspieler im
 *  Raum geschickt.

P_ARRIVEMSG                    "arrivemsg"                   
 *  Meldung, wenn der Transporter anlegt.

P_DEPARTMSG                    "departmsg"                   
 *  Meldung, mit der ein Transporter ablegt.

P_ENTERCMDS                    "entercmds"                   
 *  Befehlsliste, die zum Betreten des Transporters fuehrt.

P_LEAVECMDS                    "leavecmds"                   
 *  Befehlsliste, die zum Verlassen des Transporters fuehrt.

P_MAX_PASSENGERS               "maxpass"                     
 *  Numerischer Wert fuer die maximale Anzahl von Wesen in dem Transporter.
 *  0 bedeutet unbeschaenkte Spielerzahl.


mudlib/sys/v_compiler.h:
------------------------
P_STD_OBJECT                   "std_object"                  
 *** KEINE BESCHREIBUNG VORHANDEN ***

P_COMPILER_PATH                "compiler_path"               
 *** KEINE BESCHREIBUNG VORHANDEN ***


mudlib/sys/weapon.h:
--------------------
P_NR_HANDS                     "nr_hands"                    
 *  Anzahl der Haende, die man zur Benuztung des Objektes benoetigt.

P_WC                           "wc"                          
 *  Numerischer Wert fuer die Staerke der Waffe.

P_WEAPON_TYPE                  "weapon_type"                 
 *  Art der Waffe

P_DAM_TYPE                     "dam_type"                    
 *  String mit der Art der Verletzung.

P_WIELDED                      "wielded"                     
 *  Enthaelt, wenn die Waffe gezueckt ist, das Objekt des Spielers/NPCs,
 *  der die Waffe gezueckt hat, sonst 0.

