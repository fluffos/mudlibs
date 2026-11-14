
string desc();
int roomkind;

string desc1() {
    string *part1, *part2, *part5;
    string ret;
      part1=({
           "Du stehst ","Du haeltst ","Du findest Dich ","Du erkennst Dich ", "Du befindest Dich ",
           "Du wurzelst ", "Du erblickst Dich "});
      part2=({
         "in einem engen Gang. ", "inmitten einer engen Sackgasse. ", "am Ende eines Ganges. ",
         "vor einer Wand am Ende eines Ganges. ", "in einem engen Teil einer Sackgasse. ",
         "im Endbereich dieses Weges. ", "in einem weitlaeufigen Raum. ", "in einer schmalen Sackgasse. ",
         "inmitten eines Dich fast erdrueckenden Raums. ", "in einem stickigen Raum. ",
         "inmitten einer riesigen Sackgasse. ", "am Ende eines breiten Ganges. " });

      part5=({
         "Es fuehrt Dich ein Ausgang hier heraus.", "Es gibt nur einen Ausgang, der hier weiterfuehrt.",
         "Du erkennst eine Richtung, in der Du weitergehen kannst.", "Nur ein Weg fuehrt weiter.",
         "Du kannst nur einen Weg einschlagen, um hier vorwaerts zu kommen.", "Ein Ausgang fuehrt hier heraus." });

      ret="";
      ret=part1[random(sizeof(part1))]+part2[random(sizeof(part2))]+desc()+part5[random(sizeof(part5))];
      return ret;
}


string desc2() {
    string *part1, *part2, *part5;
    string ret;
      part1=({
           "Du stehst ","Du haeltst ","Du findest Dich ","Du erkennst Dich ", "Du befindest Dich ",
           "Du wurzelst ", "Du erblickst Dich "});
      part2=({
         "in einem engen Gang. ", "inmitten eines engen Ganges. ", "in einem langen Gang. ",
         "zwischen zwei Waenden eines Ganges. ", "in einem Teil, welcher schnurgerade weiterfuehrt. ",
         "im Durchgangsbereich dieses Wegs. ", "in einem Raum der geradlinig einen Gang bildet. ", "in einer schmalen Gasse. ",
         "inmitten eines Dich fast erdrueckenden Gangs. ", "in einem weitlaeufigen Gang. ",
         "inmitten eines riesigen Gangs. "});

      part5=({
         "Es fuehren Dich zwei Ausgaenge hier heraus.", "Es gibt zwei Ausgaenge, welche hier weiterfuehren.",
         "Du erkennst zwei Richtungen, in die Du weitergehen kannst.", "Zwei Wege fuehren weiter.",
         "Du kannst hier zwei Wege einschlagen, um vorwaerts zu kommen.", "Zwei Ausgaenge fuehren hier heraus." });

      
      ret="";
      ret=part1[random(sizeof(part1))]+part2[random(sizeof(part2))]+desc()+part5[random(sizeof(part5))];
      return ret;
}



string desc3() {
    string *part1, *part2, *part5;
    string ret;
      part1=({
           "Du stehst ","Du haeltst ","Du findest Dich ","Du erkennst Dich ", "Du befindest Dich ",
           "Du wurzelst ", "Du erblickst Dich "});
      part2=({
           "in einem engen Gang. ", "inmitten eines engen Ganges. ", "in einem langen Gang. ",
           "zwischen drei Waenden eines Ganges. ", "in einem Teil der ein T bildet. ",
           "im Durchgangsbereich dieses Wegs. ", "in einem Raum, welcher wie ein Dreizack aussieht. ", 
           "inmitten eines Dich fast erdrueckenden Gangs. ", "in einem weitlaeufigen Gang. ",
           "inmitten eines riesigen Gangs. "});

      part5=({
           "Es fuehren Dich drei Ausgaenge hier heraus.", "Es gibt drei Ausgaenge, welche hier weiterfuehren.",
           "Du erkennst drei Richtungen, in die Du weitergehen kannst.", "Drei Wege fuehren weiter.",
           "Du kannst hier drei Wege einschlagen, um vorwaerts zu kommen.", "Drei Ausgaenge fuehren hier heraus." });

      ret="";
      ret=part1[random(sizeof(part1))]+part2[random(sizeof(part2))]+desc()+part5[random(sizeof(part5))];
      return ret;
}


string desc4() {
    string *part1, *part2, *part5;
    string ret;
      part1=({
           "Du stehst ","Du haeltst ","Du findest Dich ","Du erkennst Dich ", "Du befindest Dich ",
           "Du wurzelst ", "Du erblickst Dich "});
      part2=({
           "auf einer engen Kreuzung. ", "inmitten einer engen Kreuzung. ", "auf einer Kreuzung. ",
           "zwischen zwei Wegen, die sich kreuzen. ", "in einem Teil, welcher etwas merkweurdig ist. ",
           "im Durchgangsbereich von vier einmuendenden Wegen. ", "in einem langgewogenen Raum. ", 
           "inmitten eines Dich fast erdrueckenden Gangs. ", "in einem weitlaeufigen Gang. ",
           "inmitten eines riesigen Gangs. "});

      part5=({
           "Es fuehren Dich vier Ausgaenge hier heraus.", "Es gibt vier Ausgaenge, welche hier weiterfuehren.",
           "Du erkennst vier Richtungen, in die Du weitergehen kannst.", "Vier Wege fuehren weiter.",
           "Du kannst hier vier Wege einschlagen, um vorwaerts zu kommen.", "Vier Ausgaenge fuehren hier heraus." });

      ret="";
      ret=part1[random(sizeof(part1))]+part2[random(sizeof(part2))]+desc()+part5[random(sizeof(part5))];
      return ret;
}

string desc() {
    string *part3, *part4;
    string ret;
    int x,y;
    part3=({
        "Es ist sehr heiss hier herinnen, die Waende scheinen beinahe zu gluehen. ",
        "Die ploetzliche Hitze in diesem Raum drueckt Dir den Schweiss auf die Stirn. ",
        "Diese Wahnsinnshitze in diesem Raum ist beinahe nicht auszuhaltn. ",
        "Unglaublich, das es hier so heiss sein kann. ",
        "Deine Schuhsohlen schmelzen fast bei dieser unvorstellbaren Hitze. ",
        "Du spuerst die Hitze der Umgebung wie Feuer auf deiner Haut. ",
        "Deine Wangen gluehen in Anbetracht der enormen Hitze hier drinnen. ",
        "Dir rinnt der Schweiss in den Schuhen zusammen bei der Hitze, die es ploetzlich hier drinnen hat. ",
        "Unglaublich diese Unterschiede des Klimas in den unterschiedlichen Raeumen hier drinnen. Du gluehst! ",
        "Deine Achselhaare verpuffen, als Dein heisser Schweiss ueber sie herunterrinnt. ",
        "Deine Haare scheinen fast zu schmelzen bei dieser enormen Temperatur hier drinnen. ",
        "Es ist so heiss hier drinnen, Du koenntest einen kompletten Bach aussaufen. ",
        "Du koenntest am Boden Spiegeleier kochen bei dieser Sauhitze hier drinnen. ",
        "Du wuenschst Dir einen kuehlen Wind, der die Hitze in diesem Raum etwas schwinden laesst. ",
        "Dir wird schon ganz schwindelig. Die Waerme hier von diesem Raum raubt Dir die Sinne. ",
        "Solche hohen Temperaturen hier drinnen, das gehoert doch normalerweise verboten. (..denkst Du..) ",
        "Du vertrocknest bald bei der Hitze, die es hier herinnen hat. ",
        "Die heisse Luft in diesem Raum laesst Deine Haut beinahe verbrennen. Es ist einfach zu heiss. ",
        "Ui, ist es hier heiss. Naja, wenigstens musst Du nicht mehr pissen. Alles verdampft. ",
        "Wenn Du nicht bald hier rauskommst, werden Deine Ohren zu Staub zerfallen vor lauter Hitze. ",
        "Brrr. Solch eine ploetzliche bittere Kaelte, das machst Du nicht mehr lange mit. ",
        "Es ist ganz schoen kalt hier drinnen, Du friest beinahe am Boden fest! ",
        "Solch eisige Temperaturen, das Klima schlaegt hier herinnen wirlich sehr rasch um. ",
        "Du zitterst vor lauter Kaelte. Wieso hast Du bloss Deinen Schal zu Hause gelassen? ",
        "Diese enorme Kaelte hier drinnen laesst Deinen Atem beinahe stocken. ",
        "Es ist wirklich bitterkalt in diesem Raum. Anscheinend hat jemand vergessen, die Heizrechnung zu bezahlen. ",
        "Die eisige Kaelte in diesem Raum laesst Deine Zehen in den Schuhen zusammenfrieren. ",
        "Als Du in die Luft hauchst, merkst Du erst, wie kalt es wirklich hier drinnen ist, als kleine Kristalle entstehen. ",
        "Die unwahrscheinliche Kaelte in diesem Raum raubt Dir Deine Lust am Leben. ",
        "Es ist wirklich baerig kalt hier drinnen, beinahe so kalt wie in Smoersky. ",
        "Deine Knie schlottern bei der grimmigen Kaelte in diesem unfreundlich anmutenden Raum. ",
        "Du faengst am ganzen Leib zum Zittern an, denn in diesem Raum hier ist es wirklich sehr kalt. ",
        "Deine Ohren erstarren beinahe zu Eis. Du bemerkst, dass es wahnsinnig kalt hier drinnen ist. ",
        "So fuerchterlich kalt wie es hier drinnen ist, war es wo anders noch ueberhaupt nie. ",
        "Als du versuchst einzuatmen, stockt Dir der Atem, weil die Luft so kalt ist. ",
        "Du faengst fuerchterlich zu zittern an, als Du die Kaelte in diesem Raum spuerst. ",
        "Du hoffst, Dich nicht zu verkuehlen, bei diesen polarartigen Temperaturen. ",
        "Deine Hose friert beinahe an Deine Bein an, denn es ist unwahrscheinlich kalt hier drinnen. ",
        "Deine Haare fuehlen sich an wie ein Eisklumpen, die Kaelte hier herinnen laesst sie ganz hart werden. ",
        "Deine Nase verwandelt sich hier drinnen in einen roten Knopf, denn es ist so unfassbar kalt in diesem Raum. ",
        "Die Luft hier herinnen ist ziemlich feucht, aber doch angenehm von der Temperatur her. ",
        "Es hat beinahe ein mediterranes Klima in diesem Raum, Feuchtheit liegt in der Luft. ",
        "Es ist angenehm warm in diesem Raum, doch die schwuele Feuchte hier drueckt ein wenig. ",
        "Uff, Dir rinnt der Schweiss am ganzen Koerper herunter, es ist schwuel hier drinnen. ",
        "Dunst steht in diesem Raum. Die Luftfeuchtigkeit bewegt sich anscheinend irgendwo bei 290%. ",
        "Dir perlt Wasser von den Armen. Es ist ja beinahe so feucht wie im Dschungel hier. ",
        "Was ist bloss los hier? Es sieht beinahe so aus, als waeren tropische Verhaeltnisse hier. ",
        "Schwuele Hitze. *Schwitz* Hoffentlich verkuehlst Du Dich nicht bei diesen haeufigen Temperaturunterschieden. ",
        "Die feuchte Waerme in Deiner Umgebung macht Dich irgendwie erschoepft. ",
        "Gewitterschwer drueckt die Luft auf Dich in diesem Teil deiner Umgebung. Du schwitzt ein wenig. ",
        "Es ist drueckend heiss. Doch Gott sei Dank macht die Luftfeuchtigkeit die Hitze etwas ertragbarer. ",
        "Wuerde es nicht so feucht sein hier herinnen, waere die Hitze schon beinahe stechend. ",
        "Deine Haare nehmen langsam die Feuchtigkeit des Raums hier an. Deine Frisur erinnert Dich an irgendjemanden. ",
        "Diese nasse Waerme in dem Raum hier, tut richtig gut. Du fuehlst Dich entspannt hier drinnen. ",
        "Es ist wirklich verdammt dunstig in diesem Raum, Du kannst beinahe die Hand vor Deinen Augen nicht mehr erkennen. ",
        "Huch, beinahe waerst Du gegen eine Wand gedonnert, denn es ist so feucht, dass Nebel im Raum haengt. ",
        "Mensch, Du siehst ja fast nichts hier drinnen, dicke, feuchte Nebelschwaden haengen in der Luft. ",
        "*Hust* Oh, welch angenehme Luftfeuchte hier doch herrscht! Das tut deiner Bronchitis sicher gut. ",
        "Dein ganzer Koerper fuehlt sich schon schmierig an, denn es ist alles extrem feucht in deiner Umgebung. ",
        "Du bekommst fast keine Luft mehr, es liegt ja schon mehr Wasser als sonstwas in der Luft. ",
        "Es ist angenehm in diesem Raum. Nicht zu kalt, nicht zu warm, gerade recht fuer Dich. ",
        "Ahh, endlich mal halbwegs normale Temperaturen in diesem Raum. Du fuehlst dich beinahe wohl. ",
        "Du schaust Dich verwirrt in der Gegend um, nicht kalt, nicht heiss, was ist da los? Es ist ja beinahe angenehm. ",
        "Schnell greifst Du Dir auf Deine Stirn. Du schwitzt nicht. Welch ein Glueck, dass es auch wohltemperierte Raume gibt. ",
        "Du blickst Dich genau in der Gegend um und siehst Dir alles ganz gruendlich an. ",
        "Du betrachtest den soeben betretenen Raum. Was wird Dich wohl noch erwarten? ",
        "Enspannt merkst Du, dass Dir das Klima in diesem Raum gut tut. Hoffentlich bleibt das auch so. ",
        "Voller Erwartung blickst Du Dich in diesem Raum um, findest aber auf die Schnelle nichts. ",
        "Was fuer ein wohltemperierter Raum. Richtiggehend angenehm. Du koenntest ja ein Weilchen hier bleiben. ",
        "Wo bist Du denn hier gelandet? Alles sieht so normal aus. Kann es das geben? ",
        "Du bist erleichtert, als Du Dich umsiehst und bemerkst, dass hier herinnen alles halbwegs in normalen Bahnen abgeht. ",
        "Schreckhaft siehst Du Dich in diesem komischen Raum um. Doch irgendwie scheint ja eh alles ok zu sein. ",
        "Du bist beeindruckt von der angenehmen Waerme dieses Raums. Du misst die Temperatur. 23°C. Alles klar! ",
        "Was soll denn das? Ein stinknormaler Raum? Nein, das kann nicht sein, oder? ",
        "Du bist in einem schummrig anmutenden Teil gelandet. Doch irgendwie ist es angenehm hier. ",
        "Da der Programmierer nix mehr wusste, scheint deine Umgebung ziemlich langweilig zu sein hier. ",
        "Du bist erstaunt ueber die wohlig warme Umgebungstemperatur in diesem Abschnitt. ",
        "*WUMMMS* Was war denn das? Phuu, anscheinend nur ein harmloser *WUMMS* der nichts zu bedeuten hat. ",
        "Es ist wahnsinnig angenehm hier, zumindest von der Umgebungstemperatur. ",
        "Ahh, angenehme Temperaturen hier drinnen, nur der dauernde Wechsel macht Dir zu schaffen. " });
  part4=({
        "Der Boden scheint aus Magma zu bestehen, anders kannst Du Dir die Hitze nicht erklaeren. ",
        "Selbst die Waende scheinen aus fluessigem Gestein zu bestehen, das ist ja unglaublich. ",
        "Du siehst ein kleines Feuerchen in einer der Ecken lodern. Es ist beinahe schon ein Feuer! ",
        "Flammen stechen ab und an vom Boden heraus. Du musst vorsichtig sein, damit Du Dich nicht verbrennst. ",
        "Am Boden liegen gluehende Gesteinsbrocken herum, sie leuchten in roten Abstufungen, die Du kennst. ",
        "Ein Schweisstropfen, der auf den Boden faellt, verpufft sofort und loest sich in nichts auf. ",
        "Einige Flammen fahren ab und an aus den Waenden, pass auf, sonst verbrennst Du Dich noch. ",
        "Einige gluehende Steinbrocken liegen hier am Boden. Du solltest nicht unbedingt darauftreten. ",
        "Ein kleines Flaemmchen sticht aus dem Boden, doch es verfehlt Dich komplett. Glueck gehabt. ",
        "Du schreist auf, als Du auf eine zu heisse Stelle trittst, und springst weg. Ui, Deine Fuesse brennen. ",
        "Du spuckst auf den Boden. Deine Spucke loest sich in Dampf auf. Pffffffffffffffft! ",
        "Einige Aschehaufen am Boden zeugen von vergluehten Helden die einst ihr Glueck hier vesuchten. ",
        "Oh! Ein Aschehaeufchen! Da muss wohl wer verbrannt sein. Ein schrecklicher Gedanke. ",
        "Du lehnst Dich an eine Wand an, doch als es *ZISCHHHH* macht, huepfst Du schreiend weg. Es ist alles so heiss! ",
        "Bei den vielen gluehenden Dingen hier drinnen, muesste sich ein Feuerteufel wirklich wohl fuehlen. ",
        "Am Boden kannst Du deine Fusspuren sehen. Anscheinend geschmolzenes Schuhwerk von Dir. ", 
        "*KRACH* Vor deiner Nase zerspringt ein Stein in lauter kleine Einzelteile. Glueck gehabt, Dich hat nichts erwischt. ",
        "Dir wird ganz uebel, als Du einen verkohlten Aschenhaufen eines Helden, der vor Dir hier starb, entdeckst. ",
        "Am Boden siehst Du ein kleines Lagerfeuer. Es lodert vor sich hin und heizt alles auf. ",
        "Eine riesige Flamme durchkreuzt den Raum, gluecklicherweise hat sie Dich nicht erwischt. ",
        "Einige Eiskristalle an den Waenden bestaetigen die hier herrschende Kaelte. ",
        "Die Eiszapfen an der Decke sehen wunderschoen aus, auch wenn es noch so kalt ist hier drinnen. ",
        "Der Boden ist spiegelglatt, man koennte wahrscheinlich eislaufen hier drinnen. ",
        "An den Waenden haben sich einige Eiskristalle gebildet, sie funkeln praechtig. ",
        "Die Eiskristalle an den Waenden beeindrucken Dich. Sie sehen wunderschoen aus. ",
        "Ein riesiger Eiszapfen sticht Dir ins Auge. So ein grosses Teil hast Du noch nie gesehen. " ,
        "Du kannst sogar ein wenig Schnee ausmachen, also wirklich Klimaunterschiede gibts hier drinnen. ",
        "Du rutschst beinahe aus, denn der Boden ist wirklich sehr glatt hier drinnen. ",
        "Einige Eisklumpen am Boden machen es schwierig vorwaertszukommen fuer Dich. ",
        "Huch, beinahe waerst Du gegen eine Wand geschlittert, so glatt ist alles hier drinnen. ",
        "Die Eisklumpen und Eiszapfen, die du ueberall sehen kannst, stinken Dich schoen langsam an. ",
        "Es wirklich wunderbar, dass man bei solch wunderbaren Eiskristallen vorbeikommt. ",
        "An einigen Stellen kannst Du Eis an den Waenden sehen, welches eiskalt und steinhart ist. ",
        "Im Boden spiegeln sich die Eiszapfen, welche von der Decke herunterhaengen. ",
        "Boden, Waende, Decke, alles vereist. Das ist ja toll! ",
        "Grosse Eiskristalle mit noch groesseren Eiszapfen haengen ueberall herum. ",
        "Der Boden ist total vereist, einige Schneehaufen liegen auf ihm herum. ",
        "Die Waende sind total vereist. Diese Klimawechsel in den verschiedenen Raeumen sind sagenhaft. ",
        "Schups, beinahe haett es Dir die Beine ausgerissen, ganz schoen glatt hier drinnen. ",
        "In einem Schneehaufen am Boden siehst Du einen weiteren Schneehaufen am Boden. Sinnvoll! ",
        "Einige Schlingpflanzen sind zu sehen. Sie entwickeln sich praechtig. Kein Wunder bei der Umgebung. ",
        "*GRUUUHGRUUH* Ein kleiner Vogel fliegt an Dir vorbei und verschwindet sofort wieder aus Deinem Blickfeld. ",
        "Am Boden ist viel Moos zu sehen, welches beinahe alles ueberwachsen hat. Es sieht gruen und saftig aus. ",
        "Der Boden ist hier total blank, doch die Waende sind mit Moos und Unkraut nur so ueberwuchert. ",
        "Der Raum ist mit Pflanzen ueberwuchert, bei diesen Temperaturen ja auch kein Wunder. ",
        "Viele tropische Pflanzen wachsen hier. Naja, bei tropischen Temperaturen gedeihen sie ja auch wunderbar. ",
        "Einige abgefaulte Krkmorcks liegen hier am Boden, anscheinend haben sie zu viel Wasser erwischt. ",
        "Das hier muss wohl das Pflanzenparadies sein, alles zugewachsen von oben bis unten, gerade dass Du halt durchkommst. ",
        "Von der Decke siehst Du einige Schlingpflanzen haengen. Sie sind lang, gruen und ziemlich alt. ",
        "Einige verfaulte Holzstaemme liegen herum. Sie sind mit Moos bewachsen und sehen vergammelt aus. ",
        "Verfaultes Tropenlaub liegt sinnlos in der Gegend herum. Es macht nichts, und bringt Dir auch nichts. ",
        "*UGHUUGHU* Dir war als wuerde sich ein Affe an Dir vorbeischwingen, muss aber wohl ne Taeuschung gewesen sein. ",
        "An einigen Stellen bilden sich regelrechte Wassertropfen an den Pflanzen. Kommt wohl von der Luftfeuchte. ",
        "Langes Tropengras waechst hier aus dem Boden heraus. Es sieht sehr saftig und schoen gruen aus. ",
        "*OIOIOO* Dir war als wuerde sich Justavius als Tarzan verkleidet an Dir vorbeischwingen. Bloede Sinnestaeuschung. ",
        "Tropische Pflanzen, Graeser und einige verfaulte Holzstaemme sind hier zu sehen. ",
        "Alles ist hier voller Moos bewachsen. Es laesst den Raum in praechtigem gruen erstrahlen. Sieht nett aus hier. ",
        "Viele riesige, moosbewachsene, verfaulte Holzstaemme liegen ueberall in der Gegend herum. Sie behindern Dich ein wenig beim Gehen. ",
        "Wassertropfen bilden sich hier an den Pflanzen, das kommt von der hohen Luftfeuchte. Sie glitzern ein wenig. ",
        "Einige mit Moos und Unkraut bewachsene Stellen zeigen, dass es wirklich um die 290% Luftfeuchte haben muss. ",
        "Du findest absolut nichts besonders. Es ist alles halbwegs trocken. Keine grossartigen Dinge weit und breit, oder? ",
        "Ein kleines Bueschel Gras waechst hier, welches schon halb verdoerrt aussieht, aber dennoch gruen ist. ",
        "Du siehst eine kleine Oeffnung im Boden, die aber zu klein ist zum Untersuchen, sie ist einfach winzigst. ",
        "Alles ist so schoen hier, oder nicht? Naja, Du kannst Dich nicht wirklich entscheiden, was Du davon haeltst. ",
        "*QEUEEK* Du faengst an zu grunzen, als Du vor lauter Sinnlosigkeit Deine Gedanken verlierst. Was? aeh? Hm.... ",
        "Einige Blumen wachsen hier. Sie haben viele verschiedene Farben. Rot, gruen, blau, gelb,... alles dabei! ",
        "Kleine Ueberreste eines hier verreckten Helden liegen herum. Hoffentlich musst Du nicht auch sterben. ",
        "Der Boden ist da, und Du bist da und trallalla. Du freust Dich, weil Du diesen Raum entdeckt hast. Wunderbar! ",
        "Einige Grasbueschel am Boden sind hier zu finden, Du wunderst Dich, dass sie hier ueberhaupt wachsen koennen. ",
        "Oh! Was ist das? Vertrocknetes Laub? Und kein Baum weit und breit? Wie soll denn das bittesehr funktionieren? ",
        "Du siehst einen kleinen Kaefer an der Wand hochklettern. Er ist schwarz und ekelig. ",
        "Obwohl es hier angenehm ist, machen Dich die so oft wechselnden Klimaverhaeltnisse langsam irgendwie fertig. ",
        "Am Boden krabbelt ein kleiner Kaefer an Dir vorbei. Er ist schwarz und ekelhaft. ",
        "Du siehst einige Grasbueschel von der Decke nach unten wachsen, also irgendwas laeuft hier verkehrt. ",
        "Ein kleiner Steinhaufen, der hier liegt, macht Dir das gehen etwas schwerer, doch Du schaffst das schon. ",
        "Viele kleine Grasbueschel bilden hier am Boden einen langen und sehr saftig aussehenden Grasteppich. ",
        "Einige Grasbueschel sind zu sehen. Sie wachsen aber nicht, sondern liegen nur so herum. Hat wohl wer ausgerissen. ",
        "Viele bunte Blumen sind zu sehen. Ja, es ist schon fast eine Blumenwiese. Unglaublich diese Vegetation hier. ",
        "Es ist verdammt ruhig hier drinnen. Hoffentlich bleibt das auch so, denn Du bist gerade entspannt. ",
        "Eine Kaeferhorde schleicht sich an der Wand entlang in Richtung der Decke. " });

    x=random(sizeof(part3));
    if(x<20){
      y=random(20);
      roomkind=1;
    }

    if(x>19 && x<=39){
      y=random(20)+20;
      roomkind=2;
    }
    
    if(x>39 && x<=59){
      y=random(20)+40;
      roomkind=3;
    }
    
    if(x>59 && x<=79){
      y=random(20)+60;
      roomkind=4;
    }

     ret="";
     ret=part3[x]+part4[y];
     return ret;

}
