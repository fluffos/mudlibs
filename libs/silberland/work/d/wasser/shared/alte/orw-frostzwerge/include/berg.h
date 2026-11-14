/* 
** Kurz/Langbeschreibung und Details              2001-08-15 Orw@Silberland
** fuer den Bergweg 
** 
** Update              Version   Comments
** ------------------------------------------------------------------------
** 0000-00-00            1.0     Release
**
**
*/


// Short-Descriptions
#define DET_SHORT \
([ 1:"Auf einem hohen Berg.",\
   2:"In den zerkluefteten Haengen eines Bergs.",\
   3:"Umgeben von Felsen und Eis.",\
   4:"Ein Weg auf einem Berg.",\
   5:"Ein schneebedeckter Berg.",\
   6:"In eisiger Kaelte."])


// Long-Descriptions
#define DET_LANG1 \
([ 1:"Du befindest Dich auf einem schneebedeckten Bergweg. ";\
     ({"bergweg","weg","berg","schnee","eis"}),\
   2:"Ueberall liegt Schnee auf diesem Bergweg. ";\
     ({"schnee","bergweg","weg","berg"}),\
   3:"Vorsichtig gehst Du weiter auf dem Bergweg, um nicht "\
     "im Schnee auszurutschen. ";\
     ({"bergweg","weg","schnee","berg","eis"}),\
   4:"Du stehst inmitten von Felsen und Eis, auf einem Bergweg. ";\
     ({"bergweg","weg","felsen","eis"}),\
   5:"Der Bergweg fuehrt Dich durch hohe Felswaende. ";\
     ({"bergweg","weg","berg","felswaende","waende","eis"}),\
   6:"Vorsichtig, um nicht auszurutschen, gehst Du den Bergweg entlang. ";\
     ({"bergweg","weg","berg","eis"})])

#define DET_LANG2 \
([ 1:"Gigantische Felsen ragen neben dem Weg in die Hoehe. ";\
     ({"felsen","hoehe","felswaende","waende"}),\
   2:"Steile zerklueftete Felswaende geben dem Berg ein furchteinfloessendes "\
     "Aussehen. ";\
     ({"berg","felswaende","waende","felsen","aussehen"}),\
   3:"Riesige Felsen versperren Dir die Sicht zum Gipfel. ";\
     ({"felswaende","waende","felsen","sicht","gipfel"}),\
   4:"Die eisbedeckten Felswaende des Bergs glitzern in der Sonne. ";\
     ({"felsen","berg","felswaende","waende","sonne"}),\
   5:"Der Wind pfeift durch die zerkluefteten Felswaende. ";\
     ({"wind","felsen","berg","felswaende","waende"})])

#define DET_LANG3 \
([ 1:"Am Wegesrand wachsen einige Nadelbaeume. ";\
     ({"nadelbaeume","baeume","wegesrand","rand","boden","schnee"}),\
   2:"Du findest ein paar Spuren eines Tiers auf dem schneebedeckten Boden. ";\
     ({"tier","boden","spuren","schnee"}),\
   3:"Ueberall am Boden liegen mit Schnee ueberzogene Felsbrocken. ";\
     ({"boden","schnee","felsbrocken","brocken"}),\
   4:"Vereinzelt wachsen ein paar Pflanzen durch den Schnee. ";\
     ({"pflanzen","schnee","boden"}),\
   5:"Einige Felsbrocken liegen mitten auf dem Weg und behindern Dich beim "\
     "Gehen. ";\
     ({"felsbrocken","brocken","boden","weg","schnee"})])

#define DET_LANG4 \
([ 1:"Weit unter Dir siehst Du das Meer, welches lustig in der Sonne glitzert. ";\
     ({"meer","sonne"}),\
   2:"Tief unter Dir kannst Du das Meer erkennen. ";\
     ({"meer"}),\
   3:"Der Berg wirft hier einen grossen Schatten ueber das Meer unter Dir. ";\
     ({"berg","meer","schatten"}),\
   4:"Dir wird richtig schwindlig als Du das Meer tief unter Dir betrachtest. ";\
     ({"meer"}),\
   5:"Du schaust hinunter und kannst weit unten das Meer sehen, in dem sich "\
     "die Sonne spiegelt. ";\
     ({"meer","sonne"})])

#define DET_LANG5 \
([ 1:"Irgendwo hoerst Du eine Lawine den Berg runtersausen. ";\
     ({"lawine"}),\
   2:"Ein Haufen aus Felsbrocken und Schnee neben dem Weg, scheint durch eine "\
     "Lawine entstanden zu sein. ";\
     ({"haufen","felsbrocken","brocken","schnee","lawine"}),\
   3:"Manchmal hoerst Du die Schreie einiger Seevoegel die ueber das Meer "\
     "hinweg ziehen. ";\
     ({"schreie","meer","seevoegel","voegel"}),\
   4:"In der Ferne ziehen einige kreischende Moewen vorbei. ";\
     ({"ferne","moewen"}),\
   5:"Einige hohe Wellen brechen sich an der Kueste. ";\
     ({"wellen","kueste"})])

#define DET_LANG6 \
([ 1:"Du haeltst Dich an den Felsen fest um nicht runter zu fallen.";\
     ({"felsen"}),\
   2:"Hier oben ist die Luft schon etwas duenner.";\
     ({"luft"}),\
   3:"Eine dicke Eisschicht zieht sich hier ueber die Felsen.";\
     ({"eisschicht","schicht","felsen"}),\
   4:"Wohin Du auch blickst, Eis, Schnee und Felsen.";\
     ({"eis","schnee","felsen"}),\
   5:"Langsam gewoehnst Du Dich an die Kaelte.";\
     ({"kaelte"}),\
   6:"Neben diesen hohen Felswaenden kommst Du Dir richtig klein und "\
     "erbaermlich vor.";\
     ({"felswaende","waende"}),\
   7:"Dieser Berg ist riesig und jagd Dir ganz schoen Angst ein.";\
     ({"berg", "angst"}),\
   8:"Die frische Bergluft macht die Kaelte ertraeglicher.";\
     ({"bergluft","luft","kaelte"}),\
   9:"Du atmest tief durch, um Dich von den Strapazen zu erholen.";\
     ({"strapazen"}),\
  10:"Im Schnee herumzugehen ist wirklich anstrengend.";\
     ({"schnee"}),\
  11:"Einige kleine Wolken ziehen ueber die Insel hinweg.";\
     ({"wolken","insel"}),\
  12:"Du versinkst knietief im Schnee.";\
     ({"schnee"}),\
  13:"Je weiter Du gehst, umso besser gefaellt Dir diese Insel, trotz "\
     "ihrer Kaelte.";\
     ({"insel","kaelte"}),\
  14:"Hoffentlich triffst Du auf keine wilden Tiere.";\
     ({"tiere"})])

// Detail-Descriptions
#define DET_ALL1 ([ \
  "bergweg":3;\
    "Der Weg schlaengelt sich hier durch gigantische Felswaende.";\
    ({"felswaende","waende"});\
    "Der Bergweg ist dick mit Schnee bedeckt.";({"schnee"});\
    "Du befindest Dich auf einem schmalen Bergweg.";({"bergweg","weg"}),\
  "weg":3;\
    "Gemuetlich stapfst du den Weg entlang.";({"weg"});\
    "Auf dem Weg liegt jede Menge Schnee.";({"menge","schnee"});\
    "Der Weg ist voll mit Schnee und Felsen.";({"schnee","felsen"}),\
  "schnee":3;\
    "Der Schnee leuchtet in strahlendem Weiss.";({"weiss"});\
    "Der Schnee geht Dir bis zu den Knoecheln.";({"knoecheln"});\
    "Vor lauter Schnee sieht man den Weg fast nicht mehr.";({"weg"}),\
  "mitte":3;\
    "In der Mitte der Insel ragt der hohe Berg auf.";({"insel","berg"});\
    "Die Mitte der Insel ragt weit in den Himmel.";({"insel","himmel"});\
    "Weit in den Himmel ragt der hohe Berg auf dem Du Dich befindest.";\
    ({"himmel","berg","insel"}),\
  "insel":3;\
    "Die Insel ist trotz ihrer Kaelte wunderschoen";({"kaelte"});\
    "Du befindest Dich mitten auf einem hohen Berg einer grossen Insel.";\
    ({"berg", "mitte"});\
    "Auf dieser Insel ist es eisig kalt. Die Insel besteht hauptsaechlich "\
    "aus Schnee, Eis und Fels.";({"schnee","eis","fels"}),\
  "berg":3;\
    "Der grosse Berg auf dem Du wanderst, ziert die Mitte der Insel.";\
    ({"mitte", "insel"});\
    "Der Berg ist schneebedeckt und sieht ziemlich unheimlich aus "\
    "mit seinen schroffen Felswaenden.";({"felswaende", "waende"});\
    "Ob der Berg ein Geheimnis birgt?";({"geheimnis"}),\
  "felsen":3;\
    "Schroffe Felsen ragen neben dem Weg auf.";({"weg"});\
    "Die Felsen glitzern in der Sonne.";({"sonne"});\
    "Die Felsen haben einige Risse.";({"risse"}),\
  "boden":3;\
    "Der Boden ist ueberall mit Schnee und Felsbrocken bedeckt.";\
    ({"schnee","steine","felsbrocken","brocken"});\
    "Du kannst einige Spuren im Schnee erkennen.";({"spuren", "schnee"});\
    "Hoffentlich rutschst Du nicht im Schnee aus.";({"schnee"}),\
  "wegesrand":3;\
    "Am Rand des Weges siehst Du einige Buesche.";\
    ({"rand","weg","buesche"});\
    "Am Wegesrand ist der Schnee noch um einiges hoeher."; ({"schnee"});\
    "Am Rand des Weges befinden sich hohe schroffe Felswaende.";\
    ({"rand","felswaende","waende"}),\
  "rand":3;\
    "Am Rand des Weges siehst Du einige Buesche.";\
    ({"rand","weg","buesche"});\
    "Am Wegesrand ist der Schnee noch um einiges hoeher."; ({"schnee"});\
    "Am Rand des Weges befinden sich hohe schroffe Felswaende.";\
    ({"rand","felswaende","waende"}),\
  "spuren":3;\
    "Grosse Abdruecke eines Tiers befinden sich hier auf dem Boden.";\
    ({"abdruecke","boden","tier"});\
    "Deutlich siehst Du hier Spuren im Schnee.";({"schnee"});\
    "Ein grosses Tier hat hier Spuren im Schnee hinterlassen.";\
    ({"tier","schnee"})])

#define DET_ALL2 ([ \
  "felsbrocken":3;\
    "Einige kleine und grosse Felsbrocken liegen hier im Schnee.";\
    ({"schnee"});\
    "Viele kleine und grosse Felsbrocken liegen neben dem Weg.";\
    ({"weg"});\
    "Die Felsbrocken sind wohl den Berg heruntergefallen.";({"berg"}),\
  "brocken":3;\
    "Einige kleine und grosse Felsbrocken liegen hier im Schnee.";\
    ({"schnee"});\
    "Viele kleine und grosse Felsbrocken liegen neben dem Weg.";\
    ({"weg"});\
    "Die Felsbrocken sind wohl den Berg heruntergefallen.";({"berg"}),\
  "pflanzen":3;\
    "Durch den Schnee leuchten einige gruene Pflanzen.";({"schnee"});\
    "Eine Blume steckt ihre Blaetter durch den Schnee.";\
    ({"blume","blaetter","schnee"});\
    "Ein grosser Grashalm guckt aus dem Schnee heraus.";\
    ({"grashalm","halm"}),\
  "meer":3;\
    "Das Meer glitzert hier in einem schoenen Blau.";({"blau"});\
    "Lustig brechen sich die Wellen an der Kueste.";({"wellen","kueste"});\
    "Einige Eisschollen treiben die Kueste entlang.";\
    ({"eisschollen","schollen","kueste"}),\
  "sonne":3;\
    "Die Sonne strahlt vom Himmel. Trotzdem ist es sehr kalt.";\
    ({"himmel"});\
    "Die Sonne kommt nicht gegen die Kaelte an.";({"kaelte"});\
    "Die Sonnenstrahlen tauchen den Schnee in ein geheimnisvolles "\
    "Funkeln.";({"sonnenstrahlen","strahlen","schnee","funkeln"}),\
  "sonnenlicht":3;\
    "Die Sonne strahlt vom Himmel. Trotzdem ist es sehr kalt.";\
    ({"himmel"});\
    "Die Sonne kommt nicht gegen die Kaelte an.";({"kaelte"});\
    "Die Sonnenstrahlen tauchen den Schnee in ein geheimnisvolles "\
    "Funkeln.";({"sonnenstrahlen","strahlen","schnee","funkeln"}),\
  "licht":3;\
    "Die Sonne strahlt vom Himmel. Trotzdem ist es sehr kalt.";\
    ({"himmel"});\
    "Die Sonne kommt nicht gegen die Kaelte an.";({"kaelte"});\
    "Die Sonnenstrahlen tauchen den Schnee in ein geheimnisvolles "\
    "Funkeln.";({"sonnenstrahlen","strahlen","schnee","funkeln"}),\
  "wellen":3;\
    "Kleine Wellen brechen sich an der Kueste.";({"kueste"});\
    "Die Wellen glitzern im Sonnenlicht.";({"sonnenlicht","licht"});\
    "Eisschollen schaukeln auf den Wellen lustig die Kueste entlang.";\
    ({"eisschollen","schollen","kueste"}),\
  "kueste":3;\
    "Weit unter Dir kannst Du die Kueste erkennen.";({"kueste"});\
    "Einige Voegel nisten an der Kueste.";({"voegel"});\
    "Tief unter Dir kannst Du einige Wellen erkennen, die sich "\
    "an der Kueste brechen.";({"wellen"})])

#define DET_ALL3 ([ \
  "ferne":3;\
    "Dein Blick schweift weit in die Ferne.";({"blick"});\
    "Ein paar Moewen kannst Du am Horizont sehen.";({"moewen","horizont"});\
    "In der Ferne siehst Du ein Schiff auf dem Meer fahren.";({"schiff","meer"}),\
  "moewen":3;\
    "Ein paar Moewen kannst Du am Himmel entdecken.";({"himmel"});\
    "Die Moewen fliegen schwungvoll durch die Luft.";({"luft"});\
    "Einige Moewen fliegen am Horizont vorbei.";({"horizont"}),\
  "buesche":3;\
    "Ein paar kleine Buesche wachsen neben dem Weg.";({"weg"});\
    "Die Buesche kann man vor lauter Schnee fast nicht erkennen.";\
    ({"schnee"});\
    "Schneebedeckte Buesche wachsen gleich neben dem Weg.";({"weg"}),\
  "kaelte":3;\
    "Hier ist es wirklich extrem kalt.";({"kaelte"});\
    "Eine ganz nette Insel, wenn die Kaelte nicht waere.";({"insel"});\
    "Die Kaelte macht Dir etwas zu schaffen.";({"kaelte"}),\
  "voegel":3;\
    "Das scheinen ein paar Moewen zu sein.";({"moewen"});\
    "Das koennten Moewen sein.";({"moewen"});\
    "Du kannst die Voegel nicht genau erkennen, aber Du glaubst dass "\
    "es Moewen sind.";({"moewen"}),\
  "seevoegel":3;\
    "Das scheinen ein paar Moewen zu sein.";({"moewen"});\
    "Das koennten Moewen sein.";({"moewen"});\
    "Du kannst die Voegel nicht genau erkennen, aber Du glaubst dass "\
    "es Moewen sind.";({"moewen"}),\
  "schiff":3;\
    "Am Horizont faehrt ein Schiff vorbei.";({"horizont"});\
    "Wo das wohl hinfaehrt?";({"schiff"});\
    "Ein ziemlich grosses Schiff, wo das wohl hinfahren wird?";({"schiff"}),\
  "horizont":3;\
    "Am Horizont kannst Du ein Schiff und einige Voegel erkennen.";\
    ({"schiff","voegel"});\
    "Ein Schiff und einige Voegel kannst Du von hier aus erkennen.";\
    ({"schiff","voegel"});\
    "Einige Moewen fliegen am Horizont vorbei.";({"moewen"})])

#define DET_ALL4 ([ \
  "wolken":3;\
    "Ein paar paar weisse Wolken kannst Du am Himmel erkennen.";({"himmel"});\
    "Wenige Wolken schweben ueber die Insel.";({"insel"});\
    "Die Wolken ziehen lustig ueber die Insel.";({"insel"}),\
  "eisscholle":3;\
    "Weit unter Dir treibt eine Eisscholle nahe der Kueste entlang.";({"kueste"});\
    "Eine riesige Eisscholle treibt in der Ferne die Kueste entlang.";({"kueste"});\
    "Einige Eisschollen treiben weit unten, entlang der Kueste.";\
    ({"eisschollen","schollen","kueste"}),\
  "scholle":3;\
    "Weit unter Dir treibt eine Eisscholle nahe der Kueste entlang.";({"kueste"});\
    "Eine riesige Eisscholle treibt in der Ferne die Kueste entlang.";({"kueste"});\
    "Einige Eisschollen treiben weit unten, entlang der Kueste.";\
    ({"eisschollen","schollen","kueste"}),\
  "eisschollen":3;\
    "Eine Eisscholle treibt nahe der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Eine riesige Eisscholle treibt entlang der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Einige Eisschollen treiben entlang der Kueste.";\
    ({"kueste","eisscholle","scholle"}),\
  "schollen":3;\
    "Eine Eisscholle treibt nahe der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Eine riesige Eisscholle treibt entlang der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Einige Eisschollen treiben entlang der Kueste.";\
    ({"kueste","eisscholle","scholle"}),\
  "wasser":3;\
    "Wunderbar glitzert das Wasser.";({"wasser"});\
    "Das Wasser glitzert durch das Sonnenlicht besonders schoen.";\
    ({"sonnenlicht","licht"});\
    "Viele kleine Wellen durchziehen das Wasser.";({"wellen"}),\
  "himmel":3;\
    "Ein paar paar weisse Wolken kannst Du am Himmel erkennen.";({"wolken"});\
    "Der Himmel ist leuchtend blau, nur ein paar Wolken kannst Du erkennen.";\
    ({"wolken"});\
    "Ein strahlend blauer Himmel.";({"himmel"}),\
  "eis":3;\
    "Du bist umgeben von Eis und Schnee.";({"schnee"});\
    "Wohin Du auch schaust, Du siehst nur Schnee und Eis.";({"schnee"});\
    "Pass auf das Du nicht auf dem Eis ausrutschst.";({"eis"}),\
  "fels":3;\
    "Schroffe Felsen ragen neben dem Weg auf.";({"weg","felsen"});\
    "Die Felsen glitzern in der Sonne.";({"sonne","felsen"});\
    "Die Felsen haben einige Risse.";({"risse","felsen"}),\
  "luft":3;\
    "Die Luft ist hier sehr kalt.";({"luft"});\
    "Du atmest tief ein. Ah das tut gut!";({"luft"});\
    "Ziemlich kalt, wie alles hier.";({"luft"}),\
  "bergluft":3;\
    "Die Luft ist hier sehr kalt.";({"luft"});\
    "Du atmest tief ein. Ah das tut gut!";({"luft"});\
    "Ziemlich kalt, wie alles hier.";({"luft"}),\
  "menge":3;\
    "Jede Menge Schnee...";({"schnee"});\
    "Alles hier ist mit Schnee und Eis bedeckt.";({"schnee","eis"});\
    "Ueberall liegt Schnee und Eis.";({"schnee","eis"})])

#define DET_ALL5 ([ \
  "weiss":3;\
    "Wo Du auch hinschaust, alles hier ist weiss.";({"weiss"});\
    "Der Schnee glitzert in der Sonne.";({"schnee","sonne"});\
    "Der Schnee strahlt in einem schoenen Weiss.";({"schnee"}),\
  "knoecheln":3;\
    "Bis zu den Knoecheln stapfst Du im Schnee.";({"schnee"});\
    "Der Schnee geht Dir hier bis zu den Knoecheln.";({"schnee"});\
    "Tief versinkst Du im Schnee.";({"schnee"}),\
  "geheimnis":3;\
    "Um das herauszufinden bist Du doch hier...";({"geheimnis"});\
    "Erforsche ihn doch mal ein bischen...";({"geheimnis"});\
    "Was es hier wohl zu finden gibt?";({"geheimnis"}),\
  "blau":3;\
    "Der Himmel und das Meer sind strahlend blau.";({"himmel","meer"});\
    "Himmel und Meer, beide sind blau.";({"himmel","meer"});\
    "Ein wirklich strahlendes Blau siehst Du hier.";({"blau"}),\
  "nadeln":3;\
    "Die Nadeln der Baeume sind schoen gruen, aber meist mit Schnee "\
    "bedeckt.";({"baeume","schnee"});\
    "Wirklich gut mal was anderes, als das Weiss des Schnees zu sehen.";\
    ({"weiss","schnee"});\
    "Fast alle Nadeln sind mit Schnee bedeckt.";({"schnee"}),\
  "wind":3;\
    "Der Wind blaest durch die zerkluefteten Felswaende.";\
    ({"felswaende","waende"});\
    "Der Wind verweht den Schnee.";({"schnee"});\
    "Der Wind weht Schnee vom Berg herunter.";({"schnee","berg"}),\
  "risse":3;\
    "Durch den starken Wind haben die Felsen hier schon einige Risse.";\
    ({"wind","felsen","risse"});\
    "Tiefe Risse durchziehen die Felswaende.";({"felswaende","waende"});\
    "Die Felsen sind mit vielen Rissen durchzogen.";({"felsen"}),\
  "abdruecke":3;\
    "Grosse Abdruecke eines Tiers befinden sich hier auf dem Boden.";\
    ({"abdruecke","boden","tier"});\
    "Deutlich siehst Du hier Spuren im Schnee.";({"schnee"});\
    "Ein grosses Tier hat hier Spuren im Schnee hinterlassen.";\
    ({"tier","schnee"}),\
  "blume":3;\
    "Leider kannst Du nicht erkennen um was fuer eine Blume es sich "\
    "hier handelt.";({"blume"});\
    "Du hast noch nie so eine Blume gesehn, aber sie ist sehr schoen.";\
    ({"blume"});\
    "Eine wirklich schoene Blume. Nochnie zuvor hast Du so eine Blume "\
    "gesehen.";({"blume"}),\
  "blaetter":3;\
    "Die Blaetter der Blume sind saftig gruen.";({"blume"});\
    "Die gruenen Blaetter der Blume kommen aus dem Schnee.";\
    ({"blume","schnee"});\
    "Aus dem Schnee waechst eine wunderschoene Blume mit gruenen "\
    "Blaettern.";({"blume","schnee"}),\
  "grashalm":3;\
    "Einen Grashalm sieht man hier selten.";({"grashalm","halm"});\
    "Ein einzelner Grashalm schaut aus dem Schnee.";({"schnee"});\
    "Schoen auf dem ansonsten nur mit Schnee und Eis bedeckten Weg, "\
    "mal etwas anderes zu sehen.";({"schnee","eis"}),\
  "halm":3;\
    "Einen Grashalm sieht man hier selten.";({"grashalm","halm"});\
    "Ein einzelner Grashalm schaut aus dem Schnee.";({"schnee"});\
    "Schoen auf dem ansonsten nur mit Schnee und Eis bedeckten Weg, "\
    "mal etwas anderes zu sehen.";({"schnee","eis"})])

#define DET_ALL6 ([ \
  "funkeln":3;\
    "Der Schnee funkelt hier wegen dem Sonnenlicht.";\
    ({"sonnenlicht","licht"});\
    "Lustig funkelt der Schnee in der Sonne.";({"schnee","sonne"});\
    "Gespannt betrachtest Du das Funkeln des Schnees.";({"schnee"}),\
  "blick":3;\
    "Du schaust Dich um.";({"blick"});\
    "Du blickst in die Ferne.";({"ferne"});\
    "Du schaust Dir alles genau an.";({"blick"}),\
  "baeume":3;\
    "Einige Nadelbaeume stehen neben dem Weg.";({"nadelbaeume","weg"});\
    "Die Nadeln der Baeume schimmern in der Sonne.";({"nadeln","sonne"});\
    "Du siehst hier einige Nadelbaeume am Wegesrand stehen.";\
    ({"wegesrand","rand"}),\
  "nadelbaeume":3;\
    "Einige Nadelbaeume stehen neben dem Weg.";({"nadelbaeume","weg"});\
    "Die Nadeln der Baeume schimmern in der Sonne.";({"nadeln","sonne"});\
    "Du siehst hier einige Nadelbaeume am Wegesrand stehen.";\
    ({"wegesrand","rand"}),\
  "tier":3;\
    "Was fuer ein Tier das bloss sein koennte.";({"tier"});\
    "Das muss ein ziemlich grosses Tier gewesen sein.";({"tier"});\
    "Diesem Tier moechtest Du lieber nicht begegnen.";({"tier"}),\
  "tiere":3;\
    "Hoffentlich...";({"tiere"});\
    "Es soll hier welche geben...";({"tiere"});\
    "Wilden Tieren moechtest Du lieber nicht begegnen.";({"tiere"}),\
  "angst":3;\
    "Der Berg ist wirklich beaengstigend.";({"berg"});\
    "Der eisige Wind verstaerkt Deine Angst auch noch.";({"wind"});\
    "Du beginnst zu zittern.";({"angst"}),\
  "strapazen":3;\
    "Ziemlich anstrengend diesen Berg zu besteigen.";({"berg"});\
    "Der hohe Schnee macht es nicht gerade einfacher hier zu wandern.";\
    ({"schnee"});\
    "Du solltest Dich mal ein wenig ausrasten.";({"strapazen"}),\
  "sonnenstrahlen":3;\
    "Die Sonne strahlt vom Himmel. Trotzdem ist es sehr kalt.";\
    ({"himmel"});\
    "Die Sonne kommt nicht gegen die Kaelte an.";({"kaelte"});\
    "Die Sonnenstrahlen tauchen den Schnee in ein geheimnisvolles "\
    "Funkeln.";({"sonnenstrahlen","strahlen","schnee","funkeln"}),\
  "strahlen":3;\
    "Die Sonne strahlt vom Himmel. Trotzdem ist es sehr kalt.";\
    ({"himmel"});\
    "Die Sonne kommt nicht gegen die Kaelte an.";({"kaelte"});\
    "Die Sonnenstrahlen tauchen den Schnee in ein geheimnisvolles "\
    "Funkeln.";({"sonnenstrahlen","strahlen","schnee","funkeln"})])

#define DET_ALL7 ([ \
  "felswaende":3;\
    "Schroffe, gigantische Felswaende ragen neben dem Weg auf.";({"weg"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Neben Dir gehen die Felswaende des Bergs steil nach oben.";({"berg"}),\
  "hoehe":3;\
    "Der Berg ist wirklich riesig.";({"hoehe"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Neben Dir gehen die Felswaende des Bergs steil nach oben.";\
    ({"berg","felswaende","waende"}),\
  "aussehen":3;\
    "Riesige Felswaende ragen neben Dir in die Hoehe.";\
    ({"felswaende","waende","hoehe"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Du kommst Dir ziemlich mickrig neben diesen gigantlischen Felsen vor.";\
    ({"felsen"}),\
  "sicht":3;\
    "Ueberall sind Felsen die Dir die Sicht versperren.";({"felsen"});\
    "Den Gipfel siehst Du von hier aus leider nicht.";({"gipfel"});\
    "Einige Felsen versperren Dir die Sicht zum Gipfel.";({"felsen","gipfel"}),\
  "gipfel":3;\
    "Der Gipfel ist irgendwo weit ueber Dir.";({"gipfel"});\
    "Den Gipfel siehst Du von hier aus leider nicht.";({"gipfel"});\
    "Einige Felsen versperren Dir die Sicht zum Gipfel.";({"felsen","sicht"}),\
  "schatten":3;\
    "Der Berg wirft einen maechtigen Schatten.";({"berg"});\
    "Ein riesiger Schatten legt sich ueber die Kueste.";({"kueste"});\
    "Der riesige Berg wirft einen noch riesigeren Schatten.";({"berg"}),\
  "lawine":3;\
    "Hoffentlich geraetst Du in keine.";({"lawine"});\
    "Gefaehrlich dieser Weg...";({"weg"});\
    "Viele der Felsbrocken auf dem Weg scheinen durch Lawinen hier "\
    "gelandet zu sein.";({"felsbrocken","brocken"}),\
  "haufen":3;\
    "Ein hoher Haufen aus Felsbrocken und Schnee liegt neben dem Weg.";\
    ({"felsbrocken","brocken","schnee","weg"});\
    "Der Haufen scheint durch eine Lawine entstanden zu sein.";({"lawine"});\
    "Ein wirklich hoher Haufen aus Schnee und Felsbrocken.";\
    ({"felsbrocken","brocken","schnee"}),\
  "schreie":3;\
    "Einige Voegel stossen laute Schreie aus.";({"voegel"});\
    "Es scheint sich um Moewen zu handeln.";({"moewen"});\
    "Einige Voegel fliegen laut schreinend ueber Dich hinweg.";\
    ({"voegel"}),\
  "eisschicht":3;\
    "Eine dicke Eisschicht bedeckt hier die Felsen.";({"felsen"});\
    "Die Felsen sind mit einer dicken Eisschicht ueberzogen.";({"felsen"});\
    "Eine wirklich sehr dicke Eisschicht.";({"eisschicht","schicht"}),\
  "schicht":3;\
    "Eine dicke Eisschicht bedeckt hier die Felsen.";({"felsen"});\
    "Die Felsen sind mit einer dicken Eisschicht ueberzogen.";({"felsen"});\
    "Eine wirklich sehr dicke Eisschicht.";({"eisschicht","schicht"}),\
  "waende":3;\
    "Schroffe, gigantische Felswaende ragen neben dem Weg auf.";({"weg"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Neben Dir gehen die Felswaende des Bergs steil nach oben.";({"berg"})])
