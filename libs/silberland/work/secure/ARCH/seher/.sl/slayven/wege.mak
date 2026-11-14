;SILBERLAND
; Makros:
;  /M2E   Midas to Elessar (startet am westl. Ende von Midas)
;  /E2M   Elessar to Midas (startet am oestl. Ende von El.)
;  /M2Z   Midas to Zwergenstadt (wie /M2E)
;  /Z2M   Zwergenstadt to Midas (startet beim Henk)
;  /E2Z   Elessar to Zwergenst. (wie /E2M)
;  /Z2E   Zwergenst. to Elessar (wie /Z2M)
;  /M2W   Midas to Woelfe
;  /W2M   Woelfe to Midas

;*** Teilwege
;K1  Kreuzung SW:Fischerdorf/SO:Midas/N:Silberwald
;K2  Kreuzung W:Elessar,Hobbingen/SO:Silberwald/N:Gebirge
;K3  Kreuzung W:Gebirge/NO:Kaninchen/S:Silberwald
;K4a Kreuzung Ob:Gebirge/SW:Midas/SO:Zwergenstadt
;K4b Kreuzung U:Zwerg.,Silberwald/NO:Trolllager/NW:Elessar
;K5  Kreuzung W:Elessar,Hobbingen/S:Silberwald/NO:Gebirge
;K6  Kreuzung SW:Hobbingen/N:Elessar/S:Silberwald/Gebirge
;K7  Kreuzung W:Elessar/SO:Hobbingen;Silberwald/NO:See Rhondrit
;
;M1  westl. Ende Midas
;M2  oestl. Ende Midas
;Z   Zwergenstadt Felonia (Henk)
;S   Steinstadt (Harfenquest)
;W   Woelfe
;T   Trolllager (geplant)
;F   Fischerdorf (geplant)
;E1  oestl. Ende Elessar
;E2  westl. Ende Elessar

/def M12K1=w%;w%;nw%;
/def K12M1=so%;o%;o%;
/def K12K2=n%;nw%;w%;nw%;w%;nw%;nw%;nw%;nw%;
/def K22K1=so%;so%;so%;so%;o%;so%;o%;so%;s%;
/def K22K3=n%;n%;n%;nw%;
/def K32K2=so%;s%;s%;s%;
/def K32K4a=w%;w%;nw%;n%;n%;n%;nw%;no%;
/def K4a2K3=sw%;so%;s%;s%;s%;so%;o%;o%;
/def K4a2K4b=rauf%;
/def K4b2K4a=runter%;
/def K4a2Z=so%;o%;so%;so%;n%;
/def Z2K4a=s%;nw%;nw%;w%;nw%;
/def K4b2W=no%;o%;o%;o%;no%;o%;so%;
/def W2K4b=nw%;w%;sw%;w%;w%;w%;sw%;
/def K4b2S=no%;nw%;n%;n%;n%;n%;
/def S2K4b=s%;s%;s%;s%;so%;sw%;
/def K4b2K5=nw%;w%;w%;w%;klettere runter%;w%;w%;sw%;
/def K52K4b=no%;o%;o%;klettere felswand%;o%;o%;o%;so%;
/def K52K6=w%;w%;w%;sw%;w%;s%;sw%;w%;sw%;w%;no%;no%;n%;n%;
/def K62K5=s%;s%;sw%;sw%;o%;no%;o%;no%;n%;o%;no%;o%;o%;o%;
/def K62K7=n%;nu%;n%;n%;n%;n%;n%;nw%;
/def K72K6=so%;s%;s%;s%;s%;s%;sob%;sob%;
/def K72E1=w%;klettere dorf%;
/def E12K7=runter%;o%;
/def K52K2=s%;sw%;sw%;o%;o%;o%;o%;s%;sw%;sw%;s%;no%;so%;no%;o%;s%;s%;o%;so%;o%;so%;o%;o%;
/def K22K5=w%;w%;nw%;w%;nw%;w%;n%;n%;w%;sw%;nw%;sw%;n%;no%;no%;n%;w%;w%;w%;w%;no%;no%;n%;

;*** Kombinationen
/def E2Z=ultrakurz%;/E12K7%;/K72K6%;/K62K5%;/K52K4b%;/K4b2K4a%;/K4a2Z%;lang%;schau%;
/def Z2E=ultrakurz%;/Z2K4a%;/K4a2K4b%;/K4b2K5%;/K52K6%;/K62K7%;/K72E1%;lang%;schau%;

/def M2E=ultrakurz%;/M12K1%;/K12K2%;/K22K5%;/K52K6%;/K62K7%;/k72E1%;lang%;schau%;
/def E2M=ultrakurz%;/E12K7%;/K72K6%;/K62K5%;/K52K2%;/K22K1%;/K12M1%;lang%;schau%;

/def M2W=ultrakurz%;/M12K1%;/K12K2%;/K22K3%;/K32K4a%;/K4a2K4b%;/K4b2W%;lang%;schau%;
/def W2M=ultrakurz%;/W2K4b%;/K4b2K4a%;/K4a2K3%;/K32K2%;/K22K1%;/K12M1%;lang%;schau%;

/def M2Z=ultrakurz%;/M12K1%;/K12K2%;/K22K3%;/K32K4a%;/K4a2Z%;lang%;schau%;
/def Z2M=ultrakurz%;/Z2K4a%;/K4a2K3%;/K32K2%;/K22K1%;/K12M1%;lang%;schau%;