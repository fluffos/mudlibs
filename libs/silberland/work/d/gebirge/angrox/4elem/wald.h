/* Langbeschreibung fuer den Steinwald
** 14-03-1997 Angrox@SilberLand
**
** Um zu erreichen, dass etliche verschiedene 
** Kombinationen der Langbeschreibung von Raeumen 
** mit denselben Details auftauchen, werden die 
** einzelenen Saetze in Mappings gespeichert und
** per random ausgewaehlt.
**


 So soll mal der Raum ungefaehr aussehen:
 
"(1) Du bist hier inmitten eines Steinwaldes.(2) Um Dich herum "
"erheben sich majestaetische Baeume, die allesamt hoch "
"zur Decke hinauf ragen.(3) Inmitten dieser riesigen "
"Hoehle ist die Decke im Schein deiner Lichtquelle nicht auszumachen. "
"(4) Neben Baeumen gibt es noch verschiedene Buesche, Graeser und "
"andere Pflanzen." 
"(5) Der erfrischende Wind scheint von ueberall her zu wehen, "
"jedoch fuehlst Du ihn hier weit intensiver als in "
"der Steinstadt"
*/

#define LANG_1\
([1:"Du befindest Dich inmitten eines steinernen Waldes. ",\
2:"Du bist inmitten eines Steinwaldes. ",\
3:"Du bist hier inmitten eines Steinwaldes. ",\
4:"Du befindest Dich inmitten eines Waldes, der "\
  +"vollkommen aus Stein besteht. ",\
5:"Du bist hier mitten in einem Steinwald. ",\
6:"Du stehst inmitten eines riesigen, gewaltigen Steinwaldes. "])

#define LANG_2\
([1:"Um Dich herum erheben sich majestaetische Baeume, die allesamt "\
   +"hoch zur Decke ragen. ",\
2:"Die majestaetischen Baeume erheben sich rundherum bis hoch zur "\
   +"Decke hinauf. ",\
3:"Bis hoch zur Decke hinauf erheben sich diese fantastischen Baeume. ",\
4:"Die fantastischen Baeume ragen bis weit zur Decke hinauf.",\
5:"Die maejestaetischen Steinbaeume ragen ueberall bis weit zur "\
   +"Decke hinauf. ",\
6:"Die Steinbaeume, die durchaus majestaetisch wirken, ragen sich "\
   +"bis weit zur Decke hinauf. "])
    
#define LANG_3\
([1:"Inmitten dieser riesigen Hoehle ist die Decke im Schein "\
  +"Deiner Lichtquelle nicht auszumachen. ",\
2:"Die Decke ist inmitten dieser riesigen Hoehle im Schein "\
  +"Deiner Lichtquelle nicht auszumachen. ",\
3:"Trotz des Scheines Deiner Lichtquelle ist die Decke hier, "\
  +"inmitten der Hoehle, nicht auszumachen. ",\
4:"Die Decke ist trotz des Scheines Deiner Lichtquelle nicht "\
  +"auszumachen. ",\
5:"Obwohl Du eine Lichtquelle bei Dir traegst, reicht ihr Schein "\
  +"nicht bis zur Decke der Hoehle. ",\
6:"Die Decke der Hoehle ist nicht zu erkennen, und dass, obwohl "\
  +"Du eine Lichtquelle bei Dir traegst. "])

#define LANG_4\
([1:"Neben den Steinbaeumen gibt es hier noch andere Pflanzen, "\
   +"die ebenfalls versteinert sind. Du siehst Buesche, Graeser "\
   +"und andere Gewaechse. ",\
2:"Es gibt hier neben den Steinbaeumen noch etliche andere "\
   +"Pflanzen, wie Buesche und Graeser. Auch diese Gewaechse "\
   +"sind versteinert. ",\
3:"Etliche andere Pflanzen, die hier wachsen, sind ebenfalls "\
   +"versteinert, wie zum Beispiel ein paar Buesche und "\
   +"Graeser. ",\
4:"Neben den Steinbaeumen sind noch einige andere Pflanzen "\
   +"hier, die ebenfalls versteinert sind. Du erkennst "\
   +"ein paar Buesche in der Naehe, und der Boden ist "\
   +"versteinertem Gras ueberwachsen. ",\
5:"Etliche andere Gewaechse, wie Buesche oder Graeser, sind "\
   +"ebenfalls versteinert. ",\
6:"Etliche Buesche, die neben den riesigen Steinbaeumen, "\
   +"sind ebenfalls versteinert. Der Boden ist mit Gras "\
   +"bedeckt, dass ebenfalls sehr versteinert aussieht. "])

#define LANG_5\
([1:"Der erfrischende Wind scheint von ueberall her zu wehen, "\
   +"jedoch fuehlst Du ihn hier weit intensiver als in "\
   +"der Steinstadt. ",\
2:"Von ueberall her weht ein erfrischender Wind, der noch "\
   +"belebender als derjenige in der Steinstadt ist. ",\
3:"Der Wind, der von ueberall herzukommen scheint, ist noch "\
   +"intensiver und erfrischender als in der Steinstadt. ",\
4:"Der Wind, der hier durch den Steinwald weht, scheint von "\
   +"ueberall zu kommen. Ausserdem ist er erfrischender als "\
   +"derjenige in der Steinstadt. ",\
5:"Der belebende Wind scheint von ueberall her zu kommen. Er "\
   +"ist weitaus erfrischender als in der Steinstadt. ",\
6:"Der erfrischende und belebende Wind scheint hier von "\
   +"ueberall zu kommen. "])

/*
** Mit den Details wir genau so verfahren, allerdings 
** reichen dort 3 verschiedene Varianten aus.

boden, decke, ({steinwald, wald}), baeume, hoehle, 
schein, lichtquelle, buesche, {(graeser,gras}), pflanzen, 
wind, stadt, steinstadt, stein, gewaechse
*/

#define D_GEWAECHSE\
([1:"Buesche, Baeume, Graeser.",\
  2:"Hier sind Baeume, Buesche, Graeser.",\
  3:"Viele Gewaechse sind hier: Graeser, Baeume, "\
   +"Buesche."]) 
 
#define D_STEINWALD\
([1:"Der Steinwald hat ein ganz besonderes, eigenes Flair: "\
   +"Die versteinerten Baeume verleihen der ganzen "\
   +"Szenerie einen recht unheimlichen Eindruck. ",\
2:"Der Steinwald mit seinen versteinerten Baeumen hat "\
   +"ein ganz besonderes Flair: Irgendwie wirkt die "\
   +"ganze Szenerie recht unheimlich.. ",\
3:"Der Steinwald strahlt ein seltsames Flair aus, die "\
   +"ganze Szenerie wirkt recht unheimlich auf Dich ..."])

/* Neue Details: flair, eindruck, szenerie */

 
#define D_BAEUME\
([1:"Die Baeume sind voellig versteinert. Die Blaetter und "\
   +"Aeste der Baeume sind teilweise rasiermesserscharf.",\
  2:"Die Baeume bestehen vollkommen aus kalten Stein. Die "\
   +"Aeste und Blaetter sind teilweise sehr scharf. Du "\
   +"musst schon aufpassen, dass Du Dir nicht wehtust.",\
  3:"Die Baeume sind versteinert und bestehen nun aus kaltem, "\
 +"leblosen Stein. Die rasiermesserscharfe Blaetter und Aeste, "\
 +"die von den Baeumen haengen, gemahnen Dich zur Vorsicht!"])

/* Neue Details: blaetter, aeste, vorsicht(?) */

#define D_BUESCHE\
([1:"Die Buesche sind, genauso wie der Rest hier, total "\
   +"versteinert. Die Aeste der Buesche sehen gefaehrlich "\
   +"aus.",\
2:"So wie alles hier, sind auch die Buesche versteinert. "\
   +"Die Aeste, die von den Bueschen abstehen, sehen "\
   +"gefaehrlich spitz aus.",\
3:"Die Buesche sind total versteinert und bestehen aus "\
   +"kalten, leblosen Fels."])

#define D_PFLANZEN\
([1:"Die Pflanzen hier - Buesche, Baeume, Graeser, ... - "\
   +"sind versteinert.",\
  2:"Alle Pflanzen hier sind vollkommen versteinert.",\
  3:"Die Pflanzen hier wirken grau und kalt, vollkommen"\
   +"versteinert."])


#define D_GRAS\
([1:"Das Gras ist, so wie alles hier, versteinert. Der "\
  +"Stein ist hart und scharfkantig, so dass Du aufpassen "\
  +"musst, Dich nicht zu verletzen.",\
  2:"Durch die Versteinerung ist das Gras hart und "\
  +"scharfkantig geworden.",\
  3:"Das Gras ist hart und scharfkantig, da es vollkommen "\
  +"versteinerte. Du musst hier ziemlich aufpassen, um "\
  +"Dich nicht zu verletzen."])

#define D_WIND\
([1:"Der Wind hier herunten ist erfrischend wie sonst "\
  +"nirgends.",\
  2:"Der Wind scheint hier herunten von ueberall "\
  +"herzukommen. Er ist erfrischender und belebender "\
  +"als in der Steinstadt.",\
  3:"Hier herunten ist der Wind weitaus erfrischender als "\
  +"in der Steinstadt. Er scheint von ueberall herzuwehen."])

#define D_BODEN\
([1:"Der Boden ist mit Gras bedeckt - mit versteinertem "\
  +"Gras, welches empfindlich scharfkantig und hart "\
  +"aussieht. Du siehst noch etliche andere Pflanzen.",\
  2:"Der Boden ist vollkommen mit scharfkantigen Gras "\
  +"bedeckt, welches sehr scharfkantig aussieht.",\
  3:"Am Boden waechst - oder besser wuchs - Gras, welches "\
  +"sich nun in scharfkantiges Gestein verwandelt hat."])

#define D_DECKE\
([1:"Du kannst sie im Schein Deiner Lichtquelle nicht "\
  +"erkennen.",\
  2:"Du kannst sie nicht erkennen.",\
  3:"Trotz Deiner Lichtquelle kannst Du sie nicht erkennen."])


#define D_HOEHLE\
([1:"Die Hoehle ist riesengross, so gross, dass Du "\
  +"im Schein Deiner Lampe die Decke nicht ausmachen "\
  +"kannst. In ihr befindet sich ein Wald, der "\
  +"vollkommen aus Stein zu bestehen scheint.",\
  2:"Inmitten der gewaltigen Hoehle befindet sich ein "\
  +"Wald, der aus Stein zu bestehen scheint.",\
  3:"Die Hoehle, in der Du Dich befindest, ist so gross, "\
  +"dass Du die Decke nicht ausmachen kannst. Inmitten von "\
  +"ihr befindet sich ein Wald, der aus Stein zu bestehen "\
  +"scheint."])

#define D_SCHEIN\
([1:"Na, der Schein Deiner Lichtquelle!",\
  2:"Naja, der Schein der Lichtquelle, die Du bei Dir traegst.",\
  3:"Deiner Lichtquelle."])

#define D_LICHTQUELLE\
([1:"Die hast Du bei Dir,oder?",\
  2:"Na, die hast Du bei Dir.",\
  3:"Die, die Du bei Dir traegst."])

#define D_STADT\
([1:"Die Steinstadt hast Du bereits hinter Dir gelassen.",\
  2:"Du siehst hier keine Steinstadt. Diese liegt schon "\
   +"hinter Dir ...",\
  3:"Die Steinstadt liegt bereits zurueck, Du kannst sie "\
   +"von hier nicht erkennen."])

#define D_STEIN\
([1:"Alles hier besteht aus weissem Stein. Der Stein ist "\
   +"seltsam erwaermt.",\
  2:"Der Stein ist grau und erwaermt. Alles hier, die "\
  +"Baeume, Buesche, Graeser scheinen aus diesem Stein "\
  +"zu bestehen.",\
  3:"Das Gestein, aus dem alles hier besteht, ist grau "\
  +"und seltsam erwaermt. Alles hier in dieser Hoehle "\
  +"besteht aus diesem Stein."])
  
#define D_FLAIR\
([1:"Hier herrscht ein eigentuemliches Flair ... noch "\
   +"nie zuvor hast Du so etwas wie hier gesehen ...",\
  2:"Das Flair ist sehr eigentuemlich ... alles wirkt "\
   +"unheimlich, doch Du verspuerst keinerlei Angst.",\
  3:"Das unheimlich Flair, dass hier herrscht, "\
   +"faziniert Dich eher als das es Dich abschreckt."])

  /*Szenerie == Eindruck*/
#define D_EINDRUCK\
([1:"Obwohl das alles hier einen unheimlichen "\
   +"Eindruck vermittelt, hast Du keine Angst.",\
  2:"Das alles hier sieht recht unheimlich aus, doch "\
   "seltsamerweise verspuerst Du keine Angst.",\
  3:"Trotz des unheimlich Flairs hier hast Du "\
+"keine Angst."])

  /* Neues Detail: Angst */
   
#define D_ANGST\
([1:"Du hast keine Angst.",\
  2:"Du verspuerst keinerlei Angst.",\
  3:"Komisch ... Du verspuerst nicht die geringste Angst."])

#define D_BLAETTER\
([1:"Die Blaetter der Baeume sind rasiermesserscharf. "\
   +"Du musst schon sehr aufpassen, dass Du Dich nicht "\
   +"an ihnen verletzt.",\
  2:"Die Blaetter der Baeume sind vollkommen versteinert. "\
   +"Dadurch sind sie rasiermesserscharf geworden und "\
   +"koennen Dich sehr leicht verletzen, wenn Du nicht "\
   +"aufpasst.",\
  3:"Die extrem scharfen Blaetter koennen Dich leicht "\
   +"verletzen!"])

#define D_AESTE\
([1:"Die Aeste sind durch die Versteinerung extrem spitz "\
   +"geworden. Du kannst Dich leicht an ihnen verletzen, "\
   +"wenn Du nicht aufpasst.",\
  2:"Durch die Versteinerung sind die Aeste sehr spitz und "\
   +"scharf geworden.",\
  3:"Die Aeste sind, so wie die Blaetter, sehr spitz und "\
 +"scharf und koennen Dich leicht verletzen."])

 /* Neues Detail: Versteinerung */

#define D_VERSTEINERUNG\
([1:"Alles hier wurde irgendwie versteinert ... aber wie?",\
  2:"Irgenwie wurde hier alles versteinert ... seltsam,oder?",\
  3:"Hier wurde alles zu Stein."]);

#define D_VORSICHT\
([1:"Du musst vorsichtig sein, sonst wirst Du Dich hier "\
   +"furchtbar verletzen.",\
  2:"Die Aeste und Blaetter sind hier sehr gefaehrlich, Du "\
   +"koenntest Dich schwer verletzen!",\
  3:"Pass bloss auf, sonst verletzt Du Dich hier an den "\
   +"scharfen Blaettern und Aesten schwer."])


/*
Neue Details: Versteinerung
Neue Details: flair, eindruck, szenerie 
Neue Details: blaetter, aeste, vorsicht(?)

boden, decke, ({steinwald, wald}), baeume, hoehle, 
schein, lichtquelle, buesche, {(graeser,gras}), pflanzen, 
wind, stadt, steinstadt, stein */






