;SILBERLAND Wegmakros fuer TinyFugue
;  Geschrieben von Skunk ---  e-mail: skunk@xover.ml.org
;  Version 2.2
;
;  Verbesserungen von Version 2 auf 2.1 (13.11.1997)
;  - Midas mit Hobbingen verbunden
;  - Es wird nicht mehr unbedingt auf ultrakurz und lang geschalten
;    umdefinieren von /wegan und /wegaus
;
;  Verbesserungen von Version 2.1 auf 2.2 (24.4.1998)
;  - Die Makros fuer Hobbingen wurden duch den Namen Derlim ersetzt
;  - Der Teleporter von Derlim wurde eingebunden
;  - K5 ist die Kreuzung in der Naehe vom Anvar ...
;  - Wege von Midas, Felonia, Elessar, Derlim dorthin und zurueck
;  - Midas <-> Kyranda (K)
;
;*** Makros
;  /M2E   Midas to Elessar (startet am westl. Ende von Midas)
;  /E2M   Elessar to Midas (startet am oestl. Ende von El.)
;  /M2Z   Midas to Zwergenstadt (wie /M2E)
;  /Z2M   Zwergenstadt to Midas (startet beim Henk)
;  /E2Z   Elessar to Zwergenst. (wie /E2M)
;  /Z2E   Zwergenst. to Elessar (wie /Z2M)
;  /M2W   Midas to Woelfe (wie /M2Z)
;  /W2M   Woelfe to Midas (startet vor der Hoehle der Silberwoelfe)
;  /M2F   Midas to Fischerdorf (wie /M2E)
;  /F2M   Fischerdorf to Midas (startet n des Piers)
;  /Mo2Mw Midas ost to Midas west
;  /Mw2Mo Midas west to Midas ost
;  /F2T   Fischerdorf to Tijara (/wie F2M)
;  /T2F   Tijara to Fischerdorf (Kreuzung s des Steges)
;  /M2T   Midas to Tijara (wie /M2F)
;  /T2M   Tijara to Midas (wie /T2F)
;  /E2D   Elessar to Derlim (wie /E2M)
;  /D2E   Derlim to Elessar (Hauptplatz)
;  /M2D   Midas to Derlim (wie /M2F)
;  /D2M   Hobbigen to Midas (wie /D2E)
;  /M2K5  Midas to Kreuzung 5 (Start wie /M2E)
;  /K52M  Kreuzung 5 to Midas
;  /M2K5  Elessar to Kreuzung 5 (Start wie /E2M)
;  /K52M  Kreuzung 5 to Elessar
;  /M2K5  Derlim to Kreuzung 5 (Start wie /D2E)
;  /K52M  Kreuzung 5 to Derlim
;  /Z2K5  Zwergenstadt to Kreuzung 5 (Start wie /Z2M)
;  /K52Z  Kreuzung 5 to Zwergenstadt
;  /M2K   Midas to Kyranda (OSTtor Midas)
;  /K2M   Kyranda to Midas (Bruecke Kyranda)
; 
;
; Erweiterungen fuer Seher (benutzt Teleporter)
;  wie Original nur mit +s 
;  zB: /M2Zs  Midas to Zwergenstadt fuer Seher
;
;*** Damit es nicht so scrollt wird /wegan und /wegaus verwendet
;/wegan UltrakurzModus
;/wegaus LangModus 

;*** Teilwege
;K1  Kreuzung SW:Fischerdorf/SO:Midas/N:Silberwald
;K2  Kreuzung W:Elessar,Derlim/SO:Silberwald/N:Gebirge
;K3  Kreuzung W:Gebirge/NO:Kaninchen/S:Silberwald
;K4a Kreuzung Ob:Gebirge/SW:Midas/SO:Zwergenstadt
;K4b Kreuzung U:Zwerg.,Silberwald/NO:Trolllager/NW:Elessar
;K5  Kreuzung W:Elessar,Derlim/S:Silberwald/NO:Gebirge
;K6  Kreuzung SW:Derlim/N:Elessar/S:Silberwald/Gebirge
;K7  Kreuzung W:Elessar/SO:Derlim;Silberwald/NO:See Rhondrit
;S1  Steg Fischerdorf (bei Anlegestelle)
;S2  Steg Tijara (bei Anlegestelle)
;
;*** Teleporter
;
;T1  Hauptstrasse Midas
;T2  Hoehle
;T3  Tijara
;T4  Elessar
;
;*** Startpositionen
;
;M1  westl. Ende Midas
;M2  oestl. Ende Midas
;Z   Zwergenstadt Felonia (Henk)
;S   Steinstadt (Harfenquest)
;W   Woelfe
;T   Trolllager (geplant)
;L   Zeltlager (geplant)
;K   Knarkh (geplant)
;F   Fischerdorf (n des Piers, an der Kreuzung)
;E1  oestl. Ende Elessar
;E2  westl. Ende Elessar
;T   Tijara (s Ende des Stegs, Kreuzung)
;D   Derlim (Hauptplatz)

/def wegan=ultrakurz
;/def wegaus=lang%;schau
/def wegaus=kurz

/def M12K1=w%;w%;nw
/def K12M1=so%;o%;o
/def K12K2=n%;nw%;w%;nw%;w%;nw%;nw%;nw%;nw
/def K22K1=so%;so%;so%;so%;o%;so%;o%;so%;s
/def K22K3=n%;n%;n%;nw
/def K32K2=so%;s%;s%;s
/def K32K4a=w%;w%;nw%;n%;n%;n%;nw%;no
/def K4a2K3=sw%;so%;s%;s%;s%;so%;o%;o
/def K4a2K4b=rauf
/def K4b2K4a=runter
/def K4a2Z=so%;o%;so%;so%;n
/def Z2K4a=s%;nw%;nw%;w%;nw
/def K4b2W=no%;o%;o%;o%;no%;o%;so
/def W2K4b=nw%;w%;sw%;w%;w%;w%;sw
/def K4b2S=no%;nw%;n%;n%;n%;n
/def S2K4b=s%;s%;s%;s%;so%;sw
/def K4b2K5=nw%;w%;w%;w%;klettere runter%;w%;w%;sw
/def K52K4b=no%;o%;o%;klettere felswand%;o%;o%;o%;so
/def K52K6=w%;w%;w%;sw%;w%;s%;sw%;w%;sw%;w%;no%;no%;n%;n
/def K62K5=s%;s%;sw%;sw%;o%;no%;o%;no%;n%;o%;no%;o%;o%;o
/def K62K7=n%;n%;n%;n%;n%;n%;n%;nw
/def K72K6=so%;s%;s%;s%;s%;s%;s%;s
/def K72E1=w%;klettere dorf
/def E12K7=runter%;o
/def K52K2=s%;sw%;sw%;o%;o%;o%;o%;s%;sw%;sw%;s%;no%;so%;no%;o%;s%;s%;o%;so%;o%;so%;o%;o
/def K22K5=w%;w%;nw%;w%;nw%;w%;n%;n%;w%;sw%;nw%;sw%;n%;no%;no%;n%;w%;w%;w%;w%;no%;no%;n
/def K12F=sw%;sw%;w%;sw%;sw%;s%;s%;s%;sw%;w%;w%;sw%;sw%;s%;sw
/def F2K1=no%;n%;no%;no%;o%;o%;no%;n%;n%;n%;no%;no%;o%;no%;no
/def M12M2=o%;o%;o%;o%;o%;o%;o
/def M22M1=w%;w%;w%;w%;w%;w%;w
/def K62D=sw%;s%;sw%;sw%;s%;sw%;nw%;n%;w%;sw%;so%;s%;so%;s%;sw%;sw
/def D2K6=no%;no%;n%;nw%;n%;nw%;no%;o%;s%;so%;no%;n%;no%;no%;n%;no
/def M2Ka=o%;o%;no%;n%;n%;n%;o%;o%;o%;o%;o%;o%;no%;n%;n%;n%;n%;no%;no%;no%;kletter durch pflanzen
/def K2Ma=s%;sw%;sw%;sw%;s%;s%;s%;s%;sw%;w%;w%;w%;w%;w%;w%;s%;s%;s%;sw%;w%;w

;Fischerdorf nach Tijara
/def F2S1=s%;s%;s%;sw
/def S12F=verlasse schiff%;no%;n%;n%;n
/def S12Fa=/wegan%;verlasse schiff%;no%;n%;n%;n%;/wegaus
/def S12Ma=/wegan%;verlasse schiff%;no%;n%;n%;n%;/F2E1%;schau
/def t2s2=n
/def S22t=verlasse Schiff%;s
/def S22ta=/wegan%;verlasse Schiff%;s%;/wegaus
/def cont=
/def betschiff=/echo * Betrete Schiff *%;betrete schiff
/def S12S2=/echo * Warte auf Schiff *%;/lang%;/def -1 -mregexp -t'(Karavelle)' =/betschiff%;schau%;/def -1 -t'*Hafen von Tijara*' = /cont
/def S22S1=/echo * Warte auf Schiff *%;/lang%;/def -1 -mregexp -t'(Karavelle)' =/betschiff%;schau%;/def -1 -t'*Pier von Midas*' = /cont

;Erweiterungen fuer Seher
/def M12T1=o%;o%;o%;o%;o
/def T12M1=w%;w%;w%;w%;w
/def M22T1=w%;w
/def T12M2=o%;o
/def T22Z=s%;s%;s%;s%;s%;so%;n
/def Z2T2=s%;nw%;n%;n%;n%;n%;n
/def T22K4a=s%;s%;s%;s%;s%;nw%;w%;nw
/def K4a2T2=so%;o%;so%;n%;n%;n%;n%;n
/def T42E1=o%;o
/def E12T4=w%;w
/def T42T=vorne%;w%;n%;n
/def T2T4=s%;s%;o%;hinten
/def T52D=runter
/def D2T5=kletter rauf
/def Go2M=teleportier 1
/def Go2Z=teleportier 2
/def Go2T=teleportier 3
/def Go2E=teleportier 4
/def Go2D=teleportier 5

;*** Kombinationen
/def E2Z=/wegan%;/E12K7%;/K72K6%;/K62K5%;/K52K4b%;/K4b2K4a%;/K4a2Z%;/wegaus
/def Z2E=/wegan%;/Z2K4a%;/K4a2K4b%;/K4b2K5%;/K52K6%;/K62K7%;/K72E1%;/wegaus
/def E2Zs=/wegan%;/E12T4%;/Go2Z%;/T22Z%;/wegaus
/def Z2Es=/wegan%;/Z2T2%;/Go2E%;/T42E1%;/wegaus

/def M2E=/wegan%;/M12K1%;/K12K2%;/K22K5%;/K52K6%;/K62K7%;/k72E1%;/wegaus
/def E2M=/wegan%;/E12K7%;/K72K6%;/K62K5%;/K52K2%;/K22K1%;/K12M1%;/wegaus
/def M2Es=/wegan%;/M12T1%;/Go2E%;/T42E1%;/wegaus
/def E2Ms=/wegan%;/E12T4%;/Go2M%;/T12M1%;/wegaus

/def M2W=/wegan%;/M12K1%;/K12K2%;/K22K3%;/K32K4a%;/K4a2K4b%;/K4b2W%;/wegaus
/def W2M=/wegan%;/W2K4b%;/K4b2K4a%;/K4a2K3%;/K32K2%;/K22K1%;/K12M1%;/wegaus
/def M2Ws=/wegan%;/M12T1%;/Go2Z%;/T22K4a%;/K4a2K4b%;/K4b2W%;/wegaus
/def W2Ms=/wegan%;/W2K4b%;/K4b2K4a%;/K4a2T2%;/Go2M%;/T12M1%;/wegaus

/def M2Z=/wegan%;/M12K1%;/K12K2%;/K22K3%;/K32K4a%;/K4a2Z%;/wegaus
/def Z2M=/wegan%;/Z2K4a%;/K4a2K3%;/K32K2%;/K22K1%;/K12M1%;/wegaus
/def M2Zs=/wegan%;/M12T1%;/Go2Z%;/T22Z%;/wegaus
/def Z2Ms=/wegan%;/Z2T2%;/Go2M%;/T12M1%;/wegaus

/def M2F=/wegan%;/M12K1%;/K12F%;/wegaus
/def F2M=/wegan%;/F2K1%;/K12M1%;/wegaus
/def M2Fs=/M2F
/def F2Ms=/F2M

/def Mw2Mo=/wegan%;/M12M2%;/wegaus
/def Mo2Mw=/wegan%;/M22M1%;/wegaus
/def Mw2Mos=/def Mw2Mo
/def Mo2Mws=/def Mo2Mw

/def M2T=/wegan%;/M12K1%;/K12F%;/F2S1%;/S12S2%;/def cont=/S22T
/def T2M=/wegan%;/T2S2%;/S22S1%;/def cont=/S12Ma
/def M2Ts=/wegan%;/M12T1%;/Go2T%;/T42T%;/wegaus
/def T2Ms=/wegan%;/T2T4%;/Go2M%;/T12M1%;/wegaus

/def F2T=/wegan%;/F2S1%;/S12S2%;/def cont=/S22Ta
/def T2F=/wegan%;/T2S2%;/S22S1%;/def cont=/S12Fa
/def F2Ts=/echo /wegan%;/F2K1%;/K12M1%;/M12T1%;/Go2T%;/T42T%;/wegaus
/def T2Fs=/echo /wegaus%;/T2T4%;/Go2M%;T12M1%;M2K1%;/K12F%;/wegaus

/def E2D=/wegan%;/E12K7%;/K72K6%;/K62D%;/wegaus
/def D2E=/wegan%;/D2K6%;/K62K7%;/K72E1%;/wegaus
/def E2Ds=/wegan%;/E2T4%;/Go2D%;/T52D%;/wegaus
/def D2Es=/wegan%;/D2T5%;/Go2E%;/T42E1%;/wegaus

/def M2D=/wegan%;/M12K1%;/K12K2%;/K22K5%;/K52K6%;/K62D%;/wegaus
/def D2M=/wegan%;/D2K6%;/K62K5%;/K52K2%;/K22K1%;/K12M1%;/wegaus
/def M2Ds=/wegan%;/M12T1%;/Go2D%;/T52D%;/wegaus
/def D2Ms=/wegan%;/D2T5%;/Go2M%;/T12M1%;/wegaus

/def M2K5=/wegan%;/M12K1%;/K12K2%;/K22K5%;/wegaus
/def K52M=/wegan%;/K52K2%;/K22K1%;/K12M1%;/wegaus
/def M2K5s=/M2K5
/def K52Ms=/K52M

/def M2K=/wegan%;/M2Ka%;/wegaus
/def K2M=/wegan%;/K2Ma%;/wegaus
/def M2Ks=/M2K
/def K2Ms=/K2M

/def E2K5=/wegan%;/E12K7%;/K72K6%;/K62K5%;/wegaus
/def K52E=/wegan%;/K52K6%;/K62K7%;/K72E1%;/wegaus
/def E2K5s=/E2K5
/def K52Es=/K52E

/def D2K5=/wegan%;/D2K7%;/K72K6%;/K62K5%;/wegaus
/def K52D=/wegan%;/K52K6%;/K62K7%;/K72D%;/wegaus
/def D2K5s=/D2K5
/def K52Ds=/K52D

/def Z2K5=/wegan%;/Z2K4a%;/K4a2K4b%;/K4b2K5%;/wegaus
/def K52Z=/wegan%;/K52K4b%;/K4b2K4a%;/K4a2Z%;/wegaus
/def Z2K5s=/Z2K5
/def K52Zs=/K52Z
