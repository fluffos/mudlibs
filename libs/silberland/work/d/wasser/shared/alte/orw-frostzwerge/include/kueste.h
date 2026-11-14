/* 
** Kurz/Langbeschreibung und Details              2001-07-09 Orw@Silberland
** fuer den Kuestenweg 
** 
** Update              Version   Comments
** ------------------------------------------------------------------------
** 0000-00-00            1.0     Release
**
**
*/


// Short-Descriptions
#define DET_SHORT \
([ 1:"Ein Kuestenweg.",\
   2:"Auf einem eisigen Kuestenweg.",\
   3:"Im Schnee und Eis.",\
   4:"Ein Weg an der Kueste.",\
   5:"Ein schneebedeckter Kuestenweg.",\
   6:"An einer eisigen Kueste."])


// Long-Descriptions
#define DET_LANG1 \
([ 1:"Du befindest Dich auf einem schneebedeckten Kuestenweg. ";\
     ({"kuestenweg","weg"}),\
   2:"Ueberall liegt Schnee auf diesem Kuestenweg. ";\
     ({"schnee","kuestenweg","weg"}),\
   3:"Vorsichtig gehst Du weiter auf dem Kuestenweg, um nicht "\
     "im Schnee auszurutschen. ";\
     ({"kuestenweg","weg","schnee"}),\
   4:"Du stehst mitten auf einem langen Kuestenweg. ";\
     ({"kuestenweg","weg"}),\
   5:"Hier ist der Schnee neben dem Weg besonders hoch. ";\
     ({"schnee","weg","kuestenweg"})])

#define DET_LANG2 \
([ 1:"In der Mitte der Insel befindet sich ein riesiger Berg. ";\
     ({"mitte","insel","berg"}),\
   2:"Ein riesiger Berg ragt in der Mitte der Insel auf. ";\
     ({"berg","mitte","insel"}),\
   3:"Ein hoher Berg ziert die Mitte der Insel. ";\
     ({"berg","mitte","insel"}),\
   4:"Meterhohe Felsen vereinigen sich zu einem riesigen Berg, in der Mitte "\
     "der Insel. ";\
     ({"felsen","berg","mitte","insel"}),\
   5:"In der Inselmitte befindet sich ein riesiger Berg mit schroffen Felsen. ";\
     ({"inselmitte","mitte","berg","felsen","insel"})])

#define DET_LANG3 \
([ 1:"Einige Nadelbaeume wachsen am Wegesrand. ";\
     ({"nadelbaeume","baeume","wegesrand","rand","boden"}),\
   2:"Irgendein Tier hat hier Spuren im Boden hinterlassen. ";\
     ({"tier","boden","spuren"}),\
   3:"Der Boden ist mit Schnee und Felsbrocken bedeckt. ";\
     ({"boden","schnee","felsbrocken","brocken"}),\
   4:"Einige gruene Pflanzen leuchten aus dem weissen Schnee heraus. ";\
     ({"pflanzen","schnee","boden"}),\
   5:"Vorsichtig weichst Du den Felsbrocken am Boden aus. ";\
     ({"felsbrocken","brocken","boden"})])

#define DET_LANG4 \
([ 1:"Das Meer funkelt blaeulich in der Sonne. ";\
     ({"meer","sonne"}),\
   2:"Die Sonne strahlt auf Dich herunter. ";\
     ({"sonne"}),\
   3:"Die Wellen des Meers glitzern in der Sonne. ";\
     ({"wellen","meer","sonne"}),\
   4:"Das Meer reflektiert das Sonnenlicht und leuchtet wundervoll "\
     "blaeulich. ";\
     ({"meer","sonnenlicht","licht"}),\
   5:"Eine hohe Schneewehe glitzert in der Sonne. ";\
     ({"schneewehe","wehe","sonne"})])

#define DET_LANG5 \
([ 1:"Ein kleiner gruener Strauch waechst neben dem Weg. ";\
     ({"strauch"}),\
   2:"Ein riesiges Farnbueschel waechst hier auf einem Felsbrocken. ";\
     ({"farnbueschel","bueschel","felsbrocken","brocken"}),\
   3:"Die Kueste faellt hier zum Meer hin schroff ab. ";\
     ({"kueste","meer"}),\
   4:"In der Ferne ziehen einige Moewen vorbei. ";\
     ({"ferne","moewen"}),\
   5:"Einige Steine machen hier den Weg hier begehbarer. ";\
     ({"steine"})])

#define DET_LANG6 \
([ 1:"Ein grosser Felsblock liegt hier an der Kueste.";\
     ({"felsblock","block","kueste"}),\
   2:"Gespannt gehst Du weiter am Meer entlang.";\
     ({"meer"}),\
   3:"Ein paar kleine Buesche sind fast total mit Schnee bedeckt.";\
     ({"buesche","schnee"}),\
   4:"Eine Wurzel ragt neben Dir aus dem Schnee.";\
     ({"wurzel","schnee"}),\
   5:"Bis auf die Kaelte ist es hier ganz nett.";\
     ({"kaelte"}),\
   6:"Weit draussen ueber dem Meer siehst Du ein paar Voegel.";\
     ({"meer","voegel"}),\
   7:"In einem Gebuesch neben Dir scheint sich etwas zu bewegen.";\
     ({"gebuesch", "etwas"}),\
   8:"Diese Insel ist ganz schoen gross.";\
     ({"insel"}),\
   9:"Ein grosses Schiff faehrt am Horizont vorbei.";\
     ({"schiff", "horizont"}),\
  10:"Im Schnee herumzugehen ist wirklich anstrengend.";\
     ({"schnee"}),\
  11:"Einige weisse Wolken ziehen ueber die Insel hinweg.";\
     ({"wolken","insel"}),\
  12:"Eine Eisscholle treibt neben Dir im Wasser.";\
     ({"eisscholle","scholle","wasser"}),\
  13:"Je weiter Du gehst, umso besser gefaellt Dir diese Insel, trotz "\
     "ihrer Kaelte.";\
     ({"insel","kaelte"}),\
  14:"Eine riesige Flosse taucht aus dem Wasser und verschwindet sofort "\
     "wieder im Meer.";\
     ({"flosse", "wasser", "meer"})])

// Detail-Descriptions
#define DET_ALL1 ([ \
  "kuestenweg":3;\
    "Du befindest Dich auf einem Weg der hier die Kueste entlang geht.";\
    ({"kueste"});\
    "Der Kuestenweg ist dick mit Schnee bedeckt.";({"schnee"});\
    "Du befindest Dich auf dem Kuestenweg rund um die Insel.";({"insel"}),\
  "weg":3;\
    "Gemuetlich stapfst du den Weg entlang.";({"weg"});\
    "Auf dem Weg liegt jede Menge Schnee.";({"menge","schnee"});\
    "Der Weg ist voll mit Schnee und Steinen.";({"schnee","steine"}),\
  "schnee":3;\
    "Der Schnee leuchtet in strahlendem Weiss.";({"weiss"});\
    "Der Schnee geht Dir bis zu den Knoecheln.";({"knoecheln"});\
    "Vor lauter Schnee sieht man den Weg fast nicht mehr.";({"weg"}),\
  "mitte":3;\
    "In der Mitte der Insel ragt ein hoher Berg auf.";({"insel","berg"});\
    "Die Mitte der Insel ragt weit in den Himmel.";({"insel","himmel"});\
    "Weit in den Himmel ragt ein hoher Berg in der Mitte der Insel.";\
    ({"himmel","berg","insel"}),\
  "insel":3;\
    "Die Insel ist trotz ihrer Kaelte wunderschoen";({"kaelte"});\
    "Du befindest Dich auf einer grossen Insel mit einem Berg in der Mitte.";\
    ({"berg", "mitte"});\
    "Auf dieser Insel ist es eisig kalt. Die Insel besteht hauptsaechlich "\
    "aus Schnee, Eis und Fels.";({"schnee","eis","fels"}),\
  "berg":3;\
    "Ein grosser Berg ziert die Mitte der Insel.";({"mitte", "insel"});\
    "Der Berg ist teils schneebedeckt und sieht ziemlich unheimlich aus "\
    "mit seinen schroffen Felswaenden.";({"felswaende", "waende"});\
    "Ob der Berg ein Geheimnis birgt?";({"geheimnis"}),\
  "inselmitte":3;\
    "In der Mitte der Insel ragt ein hoher Berg auf";({"insel","berg"});\
    "Die Mitte der Insel ragt weit in den Himmel.";({"insel","himmel"});\
    "Weit in den Himmel ragt ein hoher Berg in der Mitte der Insel.";\
    ({"himmel","berg","insel"}),\
  "felsen":3;\
    "Schroffe Felsen ragen neben dem Weg auf.";({"weg"});\
    "Die Felsen glitzern in der Sonne.";({"sonne"});\
    "Die Felsen haben einige Risse.";({"risse"}),\
  "boden":3;\
    "Der Boden ist ueberall mit Schnee und Steinen bedeckt.";\
    ({"schnee","steine"});\
    "Du kannst einige Spuren im Schnee erkennen.";({"spuren", "schnee"});\
    "Hoffentlich rutschst Du nicht im Schnee aus.";({"schnee"}),\
  "wegesrand":3;\
    "Am Rand des Weges siehst Du einige Buesche.";\
    ({"rand","weg","buesche"});\
    "Am Wegesrand ist der Schnee noch um einiges hoeher."; ({"schnee"});\
    "Am Rand des Weges befinden sich hohe schroffe Felsen.";\
    ({"rand","felsen"}),\
  "rand":3;\
    "Am Rand des Weges siehst Du einige Buesche.";\
    ({"rand","weg","buesche"});\
    "Am Wegesrand ist der Schnee noch um einiges hoeher."; ({"schnee"});\
    "Am Rand des Weges befinden sich hohe schroffe Felsen.";\
    ({"rand","felsen"}),\
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
  "schneewehe":3;\
    "Neben dem Weg ist eine hohe Schneewehe.";({"weg"});\
    "Aus der Schneewehe ragen einige Felsbrocken.";\
    ({"felsbrocken","brocken"});\
    "Der Schnee tuermt sich hoch neben dem Weg auf.";({"schnee","weg"}),\
  "wehe":3;\
    "Neben dem Weg ist eine hohe Schneewehe.";({"weg"});\
    "Aus der Schneewehe ragen einige Felsbrocken.";\
    ({"felsbrocken","brocken"});\
    "Der Schnee tuermt sich hoch neben dem Weg auf.";({"schnee","weg"}),\
  "strauch":3;\
    "Neben dem Weg waechst ein kleiner Strauch.";({"weg"});\
    "Ein kleiner Strauch reckt seine Zweige in die Sonne.";\
    ({"zweige","sonne"});\
    "Neben dem Weg waechst ein Strauch mit verkrueppelten Zweigen.";\
    ({"strauch","zweige"}),\
  "kueste":3;\
    "Eine Eisscholle treibt die Kueste entlang.";({"eisscholle","scholle"});\
    "Einige Voegel nisten an der Kueste.";({"voegel"});\
    "Ein kalter Wind weht ueber den Kuestenweg.";({"wind"})])

#define DET_ALL3 ([ \
  "ferne":3;\
    "Dein Blick schweift weit in die Ferne.";({"blick"});\
    "Ein paar Moewen kannst Du am Horizont sehen.";({"moewen","horizont"});\
    "In der Ferne siehst Du ein Schiff fahren.";({"schiff"}),\
  "moewen":3;\
    "Ein paar Moewen kannst Du am Himmel entdecken.";({"himmel"});\
    "Die Moewen fliegen schwungvoll durch die Luft.";({"luft"});\
    "Einige Moewen fliegen am Horizont vorbei.";({"horizont"}),\
  "steine":3;\
    "Einige Steine liegen hier auf dem Weg und machen ihn somit "\
    "begehbarer.";({"weg"});\
    "Ein paar kleinere Steine liegen hier auf dem Weg.";({"weg"});\
    "Vereinzelt liegen hier ein paar kleinere Steine auf dem Weg.";({"weg"}),\
  "felsblock":3;\
    "Ein grosser Felsblock steht an der Kueste und ist unten, von "\
    "den Wellen schon richtig ausgehoehlt.";({"kueste","wellen"});\
    "Ein grosser Felsblock steht an der Kueste, wie der dort wohl "\
    "hingekommen ist?";({"kueste"});\
    "Der Felsblock wurde von den Wellen schoen glatt geschliffen.";\
    ({"wellen"}),\
  "block":3;\
    "Ein grosser Felsblock steht an der Kueste und ist unten, von "\
    "den Wellen schon richtig ausgehoehlt.";({"kueste","wellen"});\
    "Ein grosser Felsblock steht an der Kueste, wie der dort wohl "\
    "hingekommen ist?";({"kueste"});\
    "Der Felsblock wurde von den Wellen schoen glatt geschliffen.";\
    ({"wellen"}),\
  "buesche":3;\
    "Ein paar kleine Buesche wachsen neben dem Weg.";({"weg"});\
    "Die Buesche kann man vor lauter Schnee fast nicht erkennen.";\
    ({"schnee"});\
    "Schneebedeckte Buesche wachsen gleich neben dem Weg.";({"weg"}),\
  "wurzel":3;\
    "Oh, eine Wurzel! Fast waehrst Du darueber gestolpert.";({"wurzel"});\
    "Gluecklicherweise bist Du nicht ueber die Wurzel gestolpert.";({"wurzel"});\
    "Oh, eine Wurzel! Ob die von den Bueschen stammt, die am Wegesrand "\
    "wachsen?";({"buesche","wegesrand","rand"}),\
  "kaelte":3;\
    "Hier ist es wirklich saukalt.";({"kaelte"});\
    "Eine ganz nette Insel, wenn die Kaelte nicht waere.";({"insel"});\
    "Die Kaelte macht Dir etwas zu schaffen.";({"kaelte"}),\
  "voegel":3;\
    "Das scheinen ein paar Moewen zu sein.";({"moewen"});\
    "Das koennten Moewen sein.";({"moewen"});\
    "Du kannst die Voegel nicht genau erkennen, aber Du glaubst dass "\
    "es Moewen sind.";({"moewen"}),\
  "insel":3;\
    "Die Insel scheint ganz schoen gross zu sein.";({"insel"});\
    "Wahrlich eine schoene Insel, bis auf die Kaelte.";({"kaelte"});\
    "Der grosse Berg in der Mitte der Insel fasziniert Dich.";({"berg"}),\
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
    "Eine Eisscholle treibt nahe der Kueste.";({"kueste"});\
    "Eine riesige Eisscholle treibt im Wasser.";({"wasser"});\
    "Einige Eisschollen treiben neben dem Weg im Wasser.";\
    ({"eisschollen","schollen","weg","wasser"}),\
  "scholle":3;\
    "Eine Eisscholle treibt nahe der Kueste.";({"kueste"});\
    "Eine riesige Eisscholle treibt im Wasser.";({"wasser"});\
    "Einige Eisschollen treiben neben dem Weg im Wasser.";\
    ({"eisschollen","schollen","weg","wasser"}),\
  "eisschollen":3;\
    "Eine Eisscholle treibt nahe der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Eine riesige Eisscholle treibt im Wasser.";\
    ({"wasser","eisscholle","scholle"});\
    "Einige Eisschollen treiben neben dem Weg im Wasser.";\
    ({"weg","wasser","eisscholle","scholle"}),\
  "schollen":3;\
    "Eine Eisscholle treibt nahe der Kueste.";\
    ({"kueste","eisscholle","scholle"});\
    "Eine riesige Eisscholle treibt im Wasser.";\
    ({"wasser","eisscholle","scholle"});\
    "Einige Eisschollen treiben neben dem Weg im Wasser.";\
    ({"weg","wasser","eisscholle","scholle"}),\
  "wasser":3;\
    "Wunderbar glitzert das Wasser.";({"wasser"});\
    "Das Wasser glitzert durch das Sonnenlicht besonders schoen.";\
    ({"sonnenlicht","licht"});\
    "Viele kleine Wellen durchziehen das Wasser.";({"wellen"}),\
  "flosse":3;\
    "Das war aber eine riesige Flosse!";({"flosse"});\
    "Was das wohl war?";({"flosse"});\
    "Du gruebelst was das gewesen sein koennte. Jedenfalls war es "\
    "riesig.";({"flosse"}),\
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
    "Du koenntest ihn ja mal erkunden.";({"geheimnis"});\
    "Erforsche ihn doch mal...";({"geheimnis"});\
    "Was es dort wohl zu finden gibt?";({"geheimnis"}),\
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
    "Der Wind blaest ueber den Kuestenweg.";({"kuestenweg","weg"});\
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
  "zweige":3;\
    "Neben dem Weg waechst ein kleiner verkrueppelter Strauch.";({"weg"});\
    "Ein Strauch mit komischen Zweigen waechst neben dem Weg.";\
    ({"weg","zweige"});\
    "Die Zweige des Strauchs biegen sich zur Sonne.";({"zweige","sonne"}),\
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
  "farnbueschel":3;\
    "Ein huebsches gruenes Farnbueschel waechst hier auf einem Felsbrocken.";\
    ({"felsbrocken","brocken"});\
    "Ein Farnbueschel waechst hier aus einem Felsbrocken, der aus dem "\
    "Schnee ragt.";({"felsbrocken","brocken","schnee"});\
    "Ein kleines Farnbueschel waechst neben dem Weg, sowas sieht man hier "\
    "selten.";({"weg"}),\
  "bueschel":3;\
    "Ein huebsches gruenes Farnbueschel waechst hier auf einem Felsbrocken.";\
    ({"felsbrocken","brocken"});\
    "Ein Farnbueschel waechst hier aus einem Felsbrocken, der aus dem "\
    "Schnee ragt.";({"felsbrocken","brocken","schnee"});\
    "Ein kleines Farnbueschel waechst neben dem Weg, sowas sieht man hier "\
    "selten.";({"weg"}),\
  "gebuesch":3;\
    "Hat sich da etwa etwas bewegt?";({"etwas"});\
    "Du bist Dir nicht sicher aber das Gebuesch scheint sich bewegt zu haben.";\
    ({"gebuesch"});\
    "Vielleicht wars ja auch nur der Wind, der das Gebuesch bewegt hat.";\
    ({"wind"}),\
  "etwas":3;\
    "Nein, war wohl doch nichts.";({"etwas"});\
    "Enttaeuscht stellst Du fest, dass Du Dich getaeuscht hast.";({"etwas"});\
    "Hm... Du musst Dich getaeuscht haben.";({"etwas"}),\
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
    "Schroffe Felswaende ragen neben dem Weg auf.";({"weg"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Neben Dir gehen die Felswaende des Bergs steil nach oben.";({"berg"}),\
  "waende":3;\
    "Schroffe Felswaende ragen neben dem Weg auf.";({"weg"});\
    "Der Berg sieht ziemlich furchterregend aus.";({"berg"});\
    "Neben Dir gehen die Felswaende des Bergs steil nach oben.";({"berg"})])
