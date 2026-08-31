#ifndef __ADVERBS_H__
 
#define __ADVERBS_H__
 
#define ALPHABET ({"a","b","c","d","e","f","g","h","i","j","k","l","m",\
                   "n","o","p","q","r","s","t","u","v","w","x","y","z"})
 
#define SHORT_ADV_LIST ({\
({"abs","aff","aim","ama","amu","ang","ann","anx","apo","app","ast"}),\
({"bad","bas","bit","bor","bou","bri","bri","bro","bus"}),\
({"car","cha","chi","clu","col","com","con","con","con",\
  "con","cra","cun","cur","cut","cur","cyn"}),\
({"dan","dee","dem","dep","des","dev","dir","dis",\
  "dis","dre","dou","dru"}),\
({"eag","ego","ego","end","ent","ero","evi","exc","exh"}),\
({"fan","fat","fie","fir","fli","fon","foo","fri","fun","fur"}),\
({"gen","gig","gle","gra","gra"}),\
({"hap","har","hea","hea","hel","hel","hon","hop","hor","hun","hys"}),\
({"ign","imp","ina","inn","inq","ins","ins","int",\
  "int","inw","irr","iro"}),\
({"jea","joy"}),\
({"kin","kno"}),\
({"laz","lon","lou","lov","lus"}),\
({"mad","man","mel","mer","mas","mis","mus"}),\
({"nas","nau","ner","nic","noi","non"}),\
({"obv"}),\
({"pai","pas","pat","pat","per","per","pet","phy",\
  "pla","pol","pro","pro","pro","pro"}),\
({"que","qui","qui"}),\
({"ran","rap","rea","reb","rel","rog","rud"}),\
({"sad","sad","sar","sat","sco","sea","sec","sed",\
  "sen","sen","ser","sex","sha","she","shy","sic",\
  "sil","ski","sle","sli","slo","sly","smi","smo","sof","sol","spe",\
  "str","stu","sug","sud","swe"}),\
({"tea","tea","ten","ter","tha","the","tho","tig","tir",\
  "tra","tru","tru"}),\
({"une","unh","unk"}),\
({"vic","vig","vir"}),\
({"war","wea","wea","who","wic","wil","wis","wis","wry"}),\
({}),\
({"yea"}),\
({"zan","zea","zes"}),\
})
 
#define LONG_ADV_LIST ({\
({"abse","affe","aiml","amaz","amus","angr","anno","anxi","apol",\
  "appr","asto"}),\
({"badl","bash","bitt","bore","boun","brie","bri","broa","busi"}),\
({"care","char","chil","clue","cold","comp","conf","conf","cont",\
  "cont","craz","cunn","cura","cute","curi","cyni"}),\
({"dang","deep","demo","depr","desp","devi","dirt","disa",\
  "disg","drea","doub","drun"}),\
({"eage","egoc","egoi","ende","enth","erot","evil","exci","exha"}),\
({"fana","fath","fier","firm","flir","fond","fool","frie",\
  "funn","furt"}),\
({"gent","gigg","glee","grac","grac"}),\
({"happ","harm","hear","heav","help","help","hone","hope","horn",\
  "hung","hyst"}),\
({"igno","impa","inan","inno","inqu","insa","inst","inte",\
  "inte","inwa","irri","iron"}),\
({"jeal","joyf"}),\
({"kind","know"}),\
({"lazi","long","loud","lovi","lust"}),\
({"madl","mani","mela","merr","mast","misc","musi"}),\
({"nast","naug","nerv","nice","nois","nonc"}),\
({"obvi"}),\
({"pain","pass","pati","patr","perf","pers","petu","phys",\
  "play","poli","prou","prof","prof","prof"}),\
({"ques","quic","quie"}),\
({"rand","rapi","real","rebe","reli","rogu","rude"}),\
({"sadl","sadi","sarc","sata","scor","sear","secr","sedu",\
  "sens","sens","seri","sexi","sham","shee","shyl","sick",\
  "sile","skil","slee","slig","slow","slyl",\
  "smil","smoo","soft","sole","spee","stra","stup","sugg","sudd","swee"}),\
({"tear","teas","tend","terr","than","theo","thou","tigh","tire",\
  "trag","trul","trus"}),\
({"unex","unha","unkn"}),\
({"vici","vigo","virt"}),\
({"warm","weak","wear","whol","wick","wild","wise","wist","wryl"}),\
({}),\
({"year"}),\
({"zani","zeal","zest"}),\
})
 
#define ADVERB_LIST  ({\
({"absentmindedly","affectionately","aimlessly","amazedly","amusedly",\
  "angrily","annoyedly","anxiously","apologetically","appreciatively",\
  "astonishedly"}),\
({"badly","bashfully","bitterly","boredly","bouncily","briefly",\
   "brightly","broadly","busily" }),\
({"carefully","charmingly","childishly","cluelessly","coldly",\
  "completely","confidently","confusedly","contemptuously",\
  "contendedly","crazily","cunningly","curageously","cutely",\
  "curiously","cynically" }),\
({"dangerously","deeply","demonically","depressively",\
  "desperately","devilishly","dirtily","disappontedly",\
  "disgustedly","dreamily","doubtfully","drunkenly" }),\
({"eagerly","egocentrically","egoisitically",\
  "endearingly","enthuisiastically","erotically",\
  "evilly","excitedly","exhaustedly" }),\
({"fanatically","fatherly","fiercefully","firmly",\
  "flirtatiously","fondly","foolishly","friendly",\
  "funnily","furtively" }),\
({"gently","gigglishly","gleefully","gracefully","graciously"}),\
({"happily","harmonically","heartbrokenly","heavily",\
  "helpfully","helplessly","honestly","hopefully","hornily",\
  "hungrily","hysterically" }),\
({"ignorantly","impatiently","inanely","innocently",\
  "inquiringly","insanely","instantly","intently",\
  "interestedly","inwardly","irritatedly",\
  "ironically" }),\
({"jealously","joyfully" }),\
({"kindly","knowingly" }),\
({"lazily","longingly","loudly","lovingly","lustfully" }),\
({"madly","maniacally","melancholically","merrily",\
  "masterfully","mischievously","musically" }),\
({"nastily","naughtily","nervously","nicely","noisily",\
  "nonchalantly" }),\
({"obviously" }),\
({"painfully","passionately","patiently","patronizingly",\
  "perfectly","personally","petulantly","physically",\
  "playfully","politely","proudly","professionally",\
  "profoundly","profusely" }),\
({"questinoningly","quickly","quietly" }),\
({"randomly","rapidly","really","rebelliously","relievedly",\
  "roguishly","rudely" }),\
({"sadly","sadistically","sarcastically","satanically",\
  "scornfully","searchingly","secretly","seductively",\
  "sensually","sensuously","seriously",\
  "sexily","shamelessly","sheepishly","shyly","sickly",\
  "silently","skilfully","sleepily","slightly","slowly","slyly",\
  "smilingly","smoochily","softly","solemnly","speechlessly",\
  "strangely","stupidly","suggestively","suddenly",\
  "sweetly" }),\
({"tearfully","teasingly","tenderly","terribly","thankfully",\
  "theoretically","thoughtfully","tightly","tiredly",\
  "tragically","truly","trustfully" }),\
({"unexpectedly","unhappily","unknowingly" }),\
({"viciously","vigorously","virtually" }),\
({"warmly","weakly","wearily","wholeheartedly","wickedly",\
  "wildly","wisely","wistfully","wryly" }),\
({}),\
({"yearningly"}),\
({"zanily","zealously","zestily"}),\
})
 
#endif // __ADVERBS_H__
