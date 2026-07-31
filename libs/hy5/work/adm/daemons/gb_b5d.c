// designed by Yu Jue 1999-2-21

string *gb=({
"¡@¡B¡C¡O¡Â¡¼¡L¡²¡¼¢w¡ã¡ü¡K¡¥¡¦¡§¡¨¡e¡f¡q¡r¡m¡n¡u¡v¡y¡z¡¼¡¼¡i¡j¡Ó¡Ñ¡Ò¡J£N¡¼£U£S¡å¡ä¡¼¡¼¡Ô¡¼¡¼¡ç¡¼¡ó¡ì¡í¡Ý¡¼¡Ü¡¼¡¼¡Ú¡¼¡¼¡Ø¡Ù¡Û¡î¡ï¡ñ¡ð¢X¡¬¡ª¢J¢C¡¼¢F¢G¡¼¡±¡¼¡¸¡¹¡³¡´¡·¡º¡»¡¼¡½¡µ¡¶¡°¡÷¡ö¡ô¡õ¢¤",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Æ«Æ¬Æ­Æ®Æ¯Æ°Æ±Æ²Æ³Æ´¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Æ¡Æ¢Æ£Æ¤Æ¥Æ¦Æ§Æ¨Æ©Æª¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÆµÆ¶Æ·Æ¸Æ¹ÆºÆ»Æ¼Æ½Æ¾¡¼¡¼¡¼¡¼",
"¡I¡©¡­¡¼¢H¡®¡¬¡]¡^¡¯¡Ï¡A¡Ð¡D¡þ¢¯¢°¢±¢²¢³¢´¢µ¢¶¢·¢¸¡G¡Q¡Õ¡×¡Ö¡H¢I¢Ï¢Ð¢Ñ¢Ò¢Ó¢Ô¢Õ¢Ö¢×¢Ø¢Ù¢Ú¢Û¢Ü¢Ý¢Þ¢ß¢à¢á¢â¢ã¢ä¢å¢æ¢ç¢è¡£¢@¡¤¡s¡Z¡«¢é¢ê¢ë¢ì¢í¢î¢ï¢ð¢ñ¢ò¢ó¢ô¢õ¢ö¢÷¢ø¢ù¢ú¢û¢ü¢ý¢þ£@£A£B£C¡¡¡W¡¢¡Â",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"£D£E£F£G£H£I£J£K£L£M£N£O£P£Q£R£S£T£U£V£W£X£Y£Z£[¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼£\\£]£^£_£`£a£b£c£d£e£f£g£h£i£j£k£l£m£n£o£p£q£r£s¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼£t£u£v£w£x£y£z£{£|£}£~£¡£¢£££¤£¥£¦£§£¨£©£ª£«£¬£­£®£¯£°£±£²£³£´£µ£¶£·£¸£¹£º¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¢wùù¢xùø¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¢z¡¼¡¼ùÝ¢{¡¼¡¼ùß¢|¡¼¡¼ùã¢}¡¼¡¼ùå¢uùé¡¼¡¼¡¼¡¼¡¼¡¼¢tùë¡¼¡¼¡¼¡¼¡¼¡¼¢s¡¼¡¼¡¼¡¼¡¼¡¼¡¼¢r¡¼¡¼¡¼¡¼¡¼¡¼ùä¢q¡¼¡¼ùê¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼",
"°Úªü®J®Á«u­ü«s½JÀùÄ§¸G¦ãÃª·R¹i¾b®ò¦w­Í«ö·t©¤Ói®×»ê©ù¯s¥W±Î¼õ¿¬ÃÍ¶Æ¶ø¾Ò¿DªÝ®Ã¥¶¥z§a¯¹¤K¬Í¤Ú©Þ¶[¹v§â¯ÒÅòÅQ½}ª¨¥Õ¬f¦ÊÂ\\¨Õ±Ñ«ôÞû´³¯Z·h§æ¯ë¹{ªOª©§ê©Õ¦ñÃ¤¥b¿ì²Ì¨¹À°±õº]»H¸j´Î½S°FÂé³ÄÁ½­c­M¥]½Ç­é",
"Á¡¹r«O³ù¹¡Ä_©ê³ø¼É°\\ÀjÃzªM¸O´d¨õ¥_½ú­I¨©¾X­¿¯V³Æ¾ÎµH³Q©b­f¥»²Â±YÁ^¬Ç¬¦ÂÛ°n¹G»ó¤ñ»Àµ§©¼ºÑãÉ½ª²¦ÀÅÏh¹ô§È·ô³¬±Í¹ú¥²¹@¾ÀÁuÁ×°¡Ã@Ãä½s¶S«ó«KÅÜ¤Ë¿ëÅGÄ|¹M¼Ð³C½¨ªíÅ¾åx§OÃ§±lÙyÃxÀØ»«ìè§L¦B¬`¤þªÃ»æ¬±",
"¯f¦}¬ÁµÔ¼½¼·²Úªi³Õ«k·i¹`ºä§B©­²í²ä»K´ñªy»é®·¤R­÷¸É°ð¤£¥¬¨BÃ¯³¡©ÆÀ¿²qµô§÷¤~°]¸B½òªö±mµæ½²À\\°ÑÅú´ÝºFºGÀé»a¿µ­Ü·ÉÂÃ¾ÞÁW¼Ñ±ä¯ó´Zµ¦°¼¥U´ú¼hóO´¡¤eÓ³¯ù¬dâí·g¹î§Ã®t¸Ò©î®ã°[ÄeºUÂÍÆaÅþÄñÃê²£ÄÄÅ¸©÷²s",
"³õ¹Á±`ªøÀv¸z¼t´¯ºZ°Û­Ò¶W§Û¶r´Â¼J¼é±_§nª£¨®§èºM´w¹ýº«×ë¦Ú¨°¹Ð±á§Õ¨I³¯¶XÅ¨¼µºÙ«°¾í¦¨§e­¼µ{Ãg¼á¸Û©Ó³xÁþ¯¯¦Y·ö«ù°Í¦À¿ð¦¢¹£®¢¾¦¨×¤Ø¨ª¯Í¥¸¿K¥R¨R¦ä±RÃd©â¹SÃ¥ÅC¸Y·TÄw¤³º÷âä¤¡¯äªì¥XÃo¼pÃÜ¾SÂúÞQ°£·¡",
"Â¦ÀxÅ÷ÝzÄ²³B´¢¤t¬ïÝÜ¶Ç²î³Ý¦ê½Hµ¡¼l§ÉÂô³Ð§jª¤´¨Áè««¬KÝÏ¾J®B²E¯ÂÄøÂWºï²«¯ýºÏ»ÛÃã·O²¡µü¦¹¨ë½ç¦¸Áo½µ§w¥^±qÂO´ê²Ê¾LÁL«PùO¿yÂ«ºR±Z¶Ê¯Ü·ñºé²f»A§ø¦s¤o½R¼¼·b±¹®À¿ù·f¹Fµª½D¥´¤j§b¤ïØVÀ¹±a¬p¥N¶U³U«Ý¶e",
"«å¯Ô¾á¤¦³æèXå¸Áx¥¹´á¦ý¼ª²H½Ï¼u³J·í¾×ÄÒ¿ºÀÉ¤M·oÁÐ­Ë®qÃ«¾É¨ì½_±¥¹Dµs¼w±oªºÃÞ¿Oµnµ¥Àü¹¹¾H³ö§Cºw­}¼Ä²Ã¨fº°»C¹Þ©è©³¦a¸¦²Ä«Ò§Ì»¼½lÄAÕi·¿¸KÂI¨åÀQ¹Ô¹q¦ú¨l©±±}³þ¾ý·µ¸M¥pÀJ­ä¤N±¼¦Q³¨½Õ¶^¯RºÐ½º­¡¿ÒÅ|",
"¤B¨n¥m°v³»¹©¿õ©w­q¥áªF¥V¸³À´°Ê´ÉË¾«ð­á¬}°Â§Ý¤æ°~¨§³rµk³£·þ¬rÃ}¿WÅª°ô¸@½ä§ùÁá¨{«×´ç§ªºÝµuÁë¬qÂ_½v°ï§I¶¤¹ï¼[¾·ÃÛ´°¹y§y¶w¬Þ¹PÕsÎG¦h¹ÜÎW¸ú¦·¸ö²ë¨ï´k¼Z¸¿®oÃZ«XÃB³_®Z´c¤Ì§ã¹K¶k¾j®¦¦Ó¨à¦Õº¸»ç¬|¤G",
"¶Lµo»@µ­¥ï¥F»ÖªkµWÃ¿¦|µfÂ½¼ÔÄs³«Ác¤Z·Ð¤Ïªð­S³c¥Ç¶ºªx§{ªÚ¤èªÕ©Ð¨¾§«¥é³X¯¼©ñµá«D°Ø­¸ªÎ­ê½Ú§pªÍ¼oªm¶Oªâ×ô§hª^¤À¯É¼XµI¨W¯»¾Ä¥÷©Á¼«ÁT¤¥«Ê·¬¸Á®p¾W­·ºÆ²l³{¶¾Á_¿Ø©^»ñ¦ò§_¤Ò¼Å½§¹å§ß©Ø¿ç´T¬t²Å¥ñ«RªA",
"¯B²eºÖµö¥±¨j¼¾»²­Á°y©ò²ãµÆ©²»G­u°ÆÂÐ½á´_³Å¥Iªú¤÷¸¡­t´I­rªþ°ü¿£©J¾¿¹Ç¸Ó§ï·§¶t»\\µ@¤z¥Ì§ý¬a¬ñ¨x»°·Pµz´±ÆB©£­è¿û¬û¨zºõ±^´ä§þ¿t¯o°ª»I¯Ì¿|·dÂî½Z§i­ôºqÀÁ¤àÂF¯Þª¸³Î­²¸¯®æµð»Õ¹j»Ì­Ó¦Uµ¹®Ú¸ò¯Ñ§ó©°Ã¼",
"®G¯Õ±ð¤u§ð¥\\®¥ÅÇ¨Ñ°`¤½®c¤}¾d¨E«ý°^¦@¹_¤Ä·¾­eª¯«¯ºcÁÊ°÷¶dÛ£©BãT¦ôªf©t©h¹ª¥jÅÛ°©¨¦ªÑ¬GÅU©T¶±¨í¥ÊÔl¹è¬E»o¨Ä©ä©Ç´ÃÃö©x«aÆ[ºÞÀ]ÅøºDÄé³e¥ú¼s³}ºÀ³W¦cÖºÂkÀt»Ó­y°­¸Þ¬Ñ®ÛÏ@¸÷¶Q¼D¾@ºu´ÒÁç³¢°êªG»q¹L«¢",
"Àe«Ä®ü®ó¥è®`Àb¶oéwÍÕÁú§t²[´H¨ç³Û¨u¿«¾Ù®Â§ò¾Ñ®«²k¦½º~ÉqªC¯èÀ¢Àz»¨²@°q¦n¯Ó¸¹¯E¨þ³Ü²üÛ]®Ö¥Ý©M¦ó¦X²°¸è»Òªe²U»®½ÅÅb¶P¼K¶Â²ª«Ü¬½«ë­ó¦ë¾î¿Å«íÅF«¡¯M­iÂE¬x§»¥°¬õ³ï«JµU§q«p­Ô¦Z©I¥G©¿·ä³ý¸¬­J½¹ª°½k´ò",
"©·ªê°äÅ@¤¬º­¤áªá¼MµØ·â·Æµe¦E¤Æ¸Üºi«ÞÃh²aÃaÅwÀô®ÙÁÙ½w´«±w³êºÈ¸æ·ØµA«Æ¤Û¯î·W¶ÀÁD½ÀÂ®¬Ó°Ä´q·×®Ì·E«éÁÀ¦Ç´§½÷À²«ìµî¦^·´®¬¼z¥c´f±â¸ìÂ©·|Àí¶×¿Ð»£Ã¸¸§©ü±B»î´ý²VÁÅ¬¡¥ë¤õÀò©Î´bÀN³fº×À»§£°ò¾÷·î½]¿nºß",
"¦Ù°§¸ñ¿EÃÕÂû®VÁZ½r¦N·¥´Æ¿èÄy¶°¤Î«æ¯e¨V§Y¶ú¯ÅÀ½¤L¯á¤vÁª§Þ¾¬©uÉ«²½¾¯±ªÀÙ±H±I­p°O¬J§Ò»Ú§²Ä~¬ö¹ÅÏE§¨¨Î®a¥[²óÀU¸ë¥Ò¹[°²½[»ù¬[¾r¶ùÄèºÊ°í¦yºà¶¡·Î­ÝªÓÁ}¦l½pÃµÀË¬ZÆPÆP´z¾ßÂ²»ü°Å´î¯òÂeÅ³½î½â¨£Áä½b¥ó",
"°·Ä¥¼CÀ^º¥Âq¼î«Ø»ø«¸±N¼ß¦¿Ã¦½±¼Õ¼úÁ¿¦KÂæ­°¿¼´ÔÁGµJ½¦¥æ­¥¼åÅº¼bÄZÅÍ»ÇÁB¹®¸}¬¾¨¤»åÃºµ±¶Ï±Ð»ÃÃâ¸û¥sµ¢´¦±µ¬ÒÖÅµó¶¥ºI§T¸`®ÜªN±¶·ûºÜ¼äµ²¸Ñ©j§ÙÂÇªã¬É­É¤¶¬Î»|©¡¤yµ¬¤çª÷¤µ¬zÃÌºòÀA¶ÈÂÔ¶iàÚ®Ê¸TªñÂu®û",
"ºÉ«l¯ð¹¸²ô·ú´¹ÄH¨ÊÅåºë¸e¸g¤«Äµ´ºÀVÀR¹Ò·qÃè®|µj¹t³ºÄv²b¬³µ~´ª¨sªÈ¨h­´¤[¨b¤E°s´\\±ÏÂÂ¦Ý¸¤©S´Nª¹Áù©ëª®¯j©~¾sµâ§½©C¯xÁ|ªq»E©Ú¾Ú¥¨¨ã¶Z½õ¿÷­Ñ¥yÄß¬²¼@®½ÃY®S­Â²²¨÷¸hå±ÅÌ§à±¸­ÏÀïÄ±¨M³Zµ´§¡µß¶v­x§g®m",
"«Tµ¤¯C°pÂ@³Ø©@¥d«£¶}´{·¢³Í´n¥Z³ô°É§¢¬å¬Ý±dºBÁR¦ª§Ü¤®ª¡¦Ò«þ¯N¾a©V­V¬_´Ê½WÁû¬ì´ß«y¥i´÷§J¨è«È½ÒªÖ°Ù¾ÁÀµ§|§\\ªÅ®£¤Õ±±áà¤f¦©±F¬\\­ú¸]­W»Å®w¿Ç¦j«±ÎØ¸ó¯ã¶ô¸_»û§Ö¼e´Ú¦Jµ¨¨g®ØÄq²µÃmªpÁ«²¯õÉ¿s¸ª«¶»í³È",
"õX·\\¼ì©[©ø®¹§x¬AÂX¹øÁï©U©Ô³âÄúÃ¾»¶°ÕµÜ¨Ó¿àÂÅ°ýÄæÄdÄxÁñÄõÄiøÂÅóÄýÃiÆlÄêÀÝ²w·}¯T´Y­¦®Ô®ö¼´³Ò¨c¦Ñ¨Ð«¾¹T¯Oåü°Ç¼Ö¹pÅJÁ¢½U²ÖÀwÂS¾Ý¦ØÃþ²\\Ù±·«§NÍù±ù²p¾¤ÆX¯WÂ÷ºv²z§õ¨½ÃUÂ§²ú¯ï¦O®ßÄR¼FÀyÄt¾ú§Q¡¼¨Ò«W",
"µg¥ß²ÉÃwÁõ¤O¼þ­ù­ÇÁp½¬³sÅI·G¼¦º§©©ÀÄÁyÃìÅÊ·Ò½mÂ³²D±ç¸d¨}¨â½ø¶q´½«G½Ì¼º²á¹±Àø¿R¹é¿ñ¼ã¤Fáæôï¹ù®Æ¦Cµõ¯P¦HÂyµYªLÁCÀMÁ{¾FÅì²O»þ¸î§[©ð¬ÂµÙ¹sÄÖ¹a§D²Ü­âÆF³®À­»â¥t¥O·È¯[ºh²¸ÃH¯d¼B½F¬y¬h¤»ÀsÅ¤ÄVÅ¢ÁK",
"¶©ÃbÃlÃ÷¼Ó°úºOÁMº|­®Äª¿cÆ`ÃfÄl¾Û³¿¸¸¾|ÄS¸LÅS¸ô¸ï³Àéð¸S¿ý³°¼®Æj§f¾T«Q®È¼i¹ðÁ\\¼{´â«ß²vÂoºñÅrÅËÅpÆe§Z¶Ã±°²¤±Á½ü­Û¨Ú²_ºú½×ÅÚÁ³Ã¹ÅÞÆrÆYÅ[»r¸¨¬¥Àdµ¸¶ý³Âº¿½X¿Â°¨½|¹À¶Ü®I¶R³Á½æÁÚ¯ß¿fÄCÆZº¡½¯°ÒºCº©",
"ðã¨~¯íª¼ª]¦£²õ¿ß­TÁã¤ò¥Ù¹g¥f­Z«_´U»ª¶T¤\\ª´ªT±ö¡¼¾`·Ñ¨S¬Ü´CÁâ¨C¬ü¬N´K©f´Aªù´e­ÌµÞ»XÂc·ù¿ø²r¹Ú©s½NîÅÃûÁS°gÁ¼À±¦Ì¯µ³Vªc»e±K¾­´Ö¯vºø°Ã§K«j®Y½q­±­]´yºËÂÆ¬í´ù¼q§®½°·À¥Á©×¥×±Ó¼§»Ô©ú¿Á»ï»Ê¦W©RÂÕºN",
"¼±Ä¨¼Ò½¤¿i¼¯Å]©Ù¥½²ö¾¥Àqªjºz¹æ­¯¿Ñ¦È¬Y©æ¨d¯a©i¥À¹Ó¼Ç¹õ¶Ò¼}¤ì¥Ø·üªª¿p®³­þ§o¶u¨º®R¯Ç¦»¤D¥¤­@©`«n¨kÃøÅn¼¸¸£´o¾xÕï©O¾k¤º¹à¯à©gÀO­Ùªd¥§ÀÀ§A°Î¿°°f·ÄçY©à¦~½VÂ[±É©À®QÆC³¾§¿®ºÂ¿Ä^ï¿ÆhÂì¯I±zÂfÀñ¾®¹ç",
"À¾À×¤û§á¶s¯ÃÁw¿@¹A§Ë¥£§V«ã¤k·x­hºÄ®¿À¶Äz¿Õ®@¼ÚÅÃ¼ÞÃÂ¹Ã°¸âx°Ô­wª¦©¬©Èµ]©ç±ÆµP±r´û¬£Ãk¼ï½L½Y¬ß¯`§P«q¥ãÃe®Çêå­D©ß©H§S¬¶³T¶]ªw©A­F°ö»p½ß³­°t¨Ø¨K¼Q¬Ö¯y©á²i¼ê´^½´´×¸NÁO¿±ªBÄP±·¸IËòÏìÅR§å©Ü¼Aµ\\¬s",
"°àµÊ¯h¥Ö¤Çµl»÷§¾Ä´½g°¾¤ùÄFÄÆº}¿]²¼ºJ¿h«÷ÀW³h«~¸u¥â©WÄ«µÓ¥­¾Ì²~µû«Ì©Y¼â»á±C¯}¾z­¢²Ë­å¥·¾Q¤²³@¸²µÐ»Z®H¦µ®E´¶®úÃÐÃnÂr´Á´Û´Ï±­©d¤C²Yº£¬mËP¨ä´Ñ©_ª[²¥±TÂÀ»ôºX¬èªÂÃM°_°Z¤^¥ø±Ò«´¬ä¾¹®ð¨´±ó¨Tª_°WÕt",
"«ê¬¢²oÉç¡¼¹]¤d¾EÃ±¥aÁ¾°®Àr¿ú¹X«e¼ç»º²LÄþ¹Õ´O¤íºpºj¶æµÄªÊÀðÁ¥±j·m¾õÁêºV®¨¾ôÁ@³ì¹´¥©ÀT¼ÀÂ¼®k«NÂ¬¤Á­X¥B©ÄÅÑ´Ü«I¿Ë¯³µ^¶Ôªà¾à¸V¹ì¨G«C»´²B¶É­ë²MÀº´¸Ùæ±¡³¼½Ð¼yÃ£½a¬î¥Cªô²y¨D¥}­©ªsÁÍ°Ï³I¦±Âß©}ÅX´ë",
"¨ú°ùÆT½ì¥h°éù¯ÅvîÇ¬u¥þ²¬®±¤ü¨éÄU¯ÊÍP¿a«oÄNºe½T³¶¸È¸sµM¿U¥T¬VÅ{Ä[ÄcÄWÅýÄÇÂZÂ¶·S¼ö¤Ð¤¯¤H§Ô¶´¥ô»{¤b§³¬÷¥µ¤´¤é¦¥¯ñ»Tºa¿Äº²·»®eµ³¤¾´|¬X¦×¯øÄ¯¾§À©¦p°d¨Å¦¼¤J¿È³n¨¿¿¶·ç¾U¶|¼í­Y®z¼»ÏsÂÄ¸|ÄÎ¶ëÁÉ¤T¤T",
"³Ê´²®á¶Ú³à·kÄÌ±½·A·æ¦âÀß´Ë¹¬²ï¬â±þ«b¨F¯½¶ÌÔ£·Ù¿z®Í¬ÀÐs§ü¤s§Rº´­m°{°¢¾ÕÄº¿¯µ½¦Â®°Âµ¡¼¶Ë°Ó½à®Î¤W©|»n±é®´µy¿N¨¢¤c»à¤Ö­ïªò²Ð°ø»­³D¦ÞªÙ³jÄá®gÄà¯AªÀ³]¯~¥Ó©D¦ù¨­²`®W²Ô¯«¨H¼fÂT¬ÆµÇ·Vº¯Án¥Íµc¬¹¤ÉÃ·",
"¬Ù²±³Ñ³Ó¸t®v¥¢·à¬IÀã¸Ö¤rªë¤Q¥Û¬B®É¤°­¹»k¹êÃÑ¥v¥Ú¨Ï«Ë¾p©l¦¡¥Ü¤h¥@¬U¨Æ«ø»}³u¶Õ¬O¶Ý¾½¾A¥K¨ÍÄÀ¹¢¤ó¥««î«Çµø¸Õ¦¬¤â­º¦u¹Ø±Â°â¨ü½GÃ~½­¼Ï®Þ®í§ç¿é¨ûµÎ²Q²¨®ÑÅ«±E¼ôÁ¦´»ÀÆ¸p¸¾¶Á¹«ÄÝ¥º­z¾ð§ô¦§½Ý¹Ö±f¼Æº¤",
"®¤¨ê­AºL°I¥Ï«Ó®ê¬CÁ÷Âù²n½Ö¤ôºÎµ|§mÀþ¶¶µÏ»¡ºÓ®ÒÃ{´µ¼¹¼R«ä¨p¥qµ·¦º¸v¦x¶à¥|¦ø¦ü¹}¤xªQÁq¼£¹|°e§º³^»w·j¿´Â]¹ÂÄ¬¶p«U¯À³tµ¯àô¶ì·¹±J¶DµÂ»Ä»[ºâÁö¶¦ÀH¸kÅè¸H·³ÁJ¹EÀG¯©®]·lµ«»b±ô­öÁYº¾¯ÁÂê©Ò¶ò¥L¥¦¦o¶ð",
"Ã¡¾ØÁÏ½ñ­L­a©ï¥x®õ¡¼¤ÓºA¨O§~Åu³gÅõÅy¾ÂÀÈ·ð¼æÃÓ½Í©Z´à³RºÒ±´¹Ä¬´´ö¶í·e°ó´Å½£­ð¿}­Õ½ö²I½ë¿S±ÇÀÜ·Ê¸lµå®ç°k²^³³°Q®M¯SÃÃÄË¯kÁÃ±è­ç½ð¾O´£ÃD¿á³ÚÅé´ÀÀ¡±§®÷«c±P¤Ñ²K¶ñ¥Ð²¢«ï»QµÉ¬D±ø­|²·¸õ¶KÅK©«ÆUÅ¥ÖL",
"¥Å§Ê°±«F®x®¼¸¥³q®äà¬Àû¦P»É§Íµ£±íÑ¶µ©²Îµh°½§ëÀY³z¥Y¨r¬ð¹Ï®{³~Ò\\±O¤g¦R¨ß´ø¹Î±ÀÀZ»L¸À¿Æ°h§]¤ÙÁv©ì¦«²æÀkªû¹¤¾m¾ò§´©Ý³è«õ«zµìºÚ«½¥ËÄû¬n¥~½ÜÅsÆWª±¹x¤YÖJ§¹¸J®¾±ßµp±{©{°û¸UµÃ¨L¤ý¤`ªPºô©¹©ô±æ§Ñ¦k«Â",
"ÄÞ·L¦M­³¹H®é³ò°ß±©¬°Àåºû¸«µä©e°¶°°§À½n¥¼½«¨ý¬È­G³ÞÃQ¦ì´ô¿×±L¼¢½Ã½E·Å°A¤å»D¯¾§kÃ­¯¿°Ý¶ä¯ÎÏØ¾â½½´õºÛ§ÚºWª×´¤¨U§Å¶ãÂë¯Q¦Ã»z«ÎµL¿¾±ï§^§d¤ðªZ¤­®¸¤È»R¥î«V¶õ¥³Ãú±àª«¤Å°È®©»~©õº³ªR¦èÖ´ª¿´·¼H§l¿üÄë",
"µ}®§§Æ±x½¥¤i±¤º¶²m·Ë¦ÁµRÀÊÅ§®u²ß·@³ß»Ñ¬~¨t»ØÀ¸²Ó½M½¼§XÁøÁÒ·v®l«L¯U¤U·H®LÀ~±È¡¼¥ý¥PÂAÅÖ«w½å»Î²ì¶~²C©¶¶ûÅãÀI²{Äm¿¤¸¢À`¸r¾Ë³´­­½u¬Û´[Æ^­»½cÁ¸´ð¶mµ¾²»¸Ô·QÅT¨É¶µ«Ñ¾ó¹³¦V¶H¿½µv¾]«d­ýÄÛ¾P®ø®d²c¾å",
"¤p§µ®Õ¨v¼S¯º®Ä·¤¨Ç·²ÃÈ¾c¨ó®µÄâ¨¸±×¯Ù¿Ó¼g±ñ¨øÃÉ¾ÓªnÂmÁÂ®hÁ~ªä¾NªY¨¯·sÊã¤ß«Hôµ¬P¸{µV´i¿³¦D«¬§Î¨·¦æ¿ô©¯§ö©Ê©m¥S¤¿¯Ý¦I¬¤¶¯ºµ¥ð­×²Û¦´¶åÄÃ¨q³SÂ¸¼V¦¦»Ýµê¼N¶·®}³\\»W³¤±Ô¦°§Ç¯b«òµ¶´BºüÄò°a³Ù«ÅÄa±Û¥È",
"¿ïÅ~¯tµº¹uÁ§¾Ç¥Þ³·¦å³ÔâÀ´`¦¯¸ß´M¹¥¨µ®î¦Ä°V°T»¹¨³À£©ã¾~Àn§r¤XªÞ¤ú°H±V¸Å²P¶®°×¨È³Y²j«|ìI·Ï²TÆQÄY¬ããé©¥©µ¨¥ÃCÀFª¢ªu©a±»²´­lºtÆA³÷¿P¹½µx¶­­ñ«ÛµK®b¿ÎÅç¬o¥¡Àm¯±·¨´­¨ËºÅ¦Ï¬v¶§®ñ¥õÖ}¾i¼ËºyÁÜ¸y§¯º½",
"·n³ó»»½`ÁÁ«À«r¯æÃÄ­nÄ£·¦¼O­C·Ý³¥§M¤]­¶±³·~¸­¦²µÅ©]²G¤@³üÂå´¥äv¨Ì¥ì¦çÀ[¦i¿ò²¾»ö¯ØºÃ¨^©y«¼ÂU´ÈÃÆ­Ê¤w¤A¨o¥HÃÀ§í©ö¨¶¦z»õ§ÐÁr¶h¸w¬Ì¥ç¸Ç·N¼Ý¾Ð¸q¯q·¸¸ÚÄ³½ËÄ¶²§Ál²ÝÃ¶¯ô½®¦]®ï­µ³±«Ã§u»È²]±G¶¼¤¨¤ÞÁô",
"¦L­^ÄåÀ¦ÆNÀ³ÅÕ¼ü¿ÃÀçº·ÃÇªïÄ¹¬Õ¼v¿oµw¬M³é¾Ö¦þÁs÷ê±e¹l¿ã¸ºµúªa¯F¥Ã±v«i¥Î«ÕÀu±y¼~¤×¥Ñ¶l¹\\µSªo´å¨»¦³¤Í¥k¦ö¹V»¤¤S¥®¨±²J¤_ª»·®¸··MÁÖ§E«\\¹O³½´r´üº®¶¨¤©®T«B»PÀ¬¬ê¦t»y¦Ð¥É°ì¨¡­§¦S¹J³ë®n±s·U±ýº»¨|ÅA",
"¯D´J¸Î¹w¿Ý¶¿Àp²W­Þ¤¸«®°K­ì´©ÁÕ¶é­û¶ê·á·½½t»·­bº@«è°|¤ê¬ù¶VÅDÆ_©¨¸f¤ë®®¾\\¯Ð¤ªà¨¤Ã¹k¤¹¹BÄ­Áß·wÃý¥¥¥`¯{Âø®â«v¨a®_¸ü¦A¦b«¥öã¼ÈÃÙÅBÅ¦¸®¾DÁVÆwÄ¦´Ç¦­¾þ°DÄ¼¾¸³y¨m¨_Àê³d¾Ü«h¿A¸é«ç¼W¼¨´¿ÃØ¤ã³å´í¥¾ªî",
"îÔ¹h¯w¬]º^©Q¥E¬µ¶BºKÂN¦v¯¶¶Å¹ëÂ¤ÀÖ¸âÖßªg·ø±ÙÁÓ¹ñ®iÅÙ´Ì¥e¾Ô¯¸´ïºì¼Ì³¹¹üºs±i´xº¦§ú¤V±b½ã¥MµÈ¿`»Ù©Û¬L§äªh»¯·Ó¸n¥ü»F¥l¾B§é­õîhÂáªÌëã½©³o®ý¬Ã·r¯uºÂ¯z¿²­s°w°»ªE¯l¶E¾_®¶Âí°}»]±Ã¸C©º²uª§©Ã¾ã¬@¥¿¬F",
"´V¯g¾GµýªÛªK¤ä§s»jª¾ªÏ¯×¥Ä¤§Â´Â¾ª½´Ó´Þ°õ­ÈË»§}«ü¤î³k¥u¦®¯È§Ó¼°ÂY¦Ü­P¸m¼m«Ï¨î´¼¯´¸X½èª¥²©º¢ªv²¿¤¤¬Ø©¾ÄÁ°J²×ºØ¸~­«¥ò²³¦à©P¦{¬wî¤µ°¶b¨y©ª©G½K©z±ÞÆJ¯]®èµï¦¶½Þ½Ñ¸Ý³v¦ËÀëµN©ÖÆfÅñ¥DµÛ¬W§U³E¶JÅ±µ®",
"¦íª`¯¬¾n§ì¤ö«û±M¿jÂà¼¶ÁÈ½f¼ÎÉÜ¸Ë§©¼²§§ª¬´ÕÀ@°lÂØ¼Yºó½Î­ã®»©å¨ô®àµZ­_°u°ÖµÛ¨`¿B¯÷«t¸ê«º´þ²d§¶µµ¥J¬ó·º¤l¦Ûº{¦rÃO´ÄÂÜ©vºîÁ`Áa¹Q¨««µ´~¯²¨¬¨ò±Ú¯ª¶Aªý²ÕÆpÄ¡¼L¾K³Ì¸o´L¿í¬Q¥ª¦õ¬g°µ§@§¤®y¡¼¡¼¡¼¡¼¡¼",
"ÉHÉF¤a¤¢¤Ü¤Ê¥A¥å¥à°¬Ñe¾µ¡¼¬ë¡¼¤PÉG¤Ô¤ø¥g¥ÂÉÇ­NØP·¶¸A¡¼¡¼«EèóÉA¥äÉQªË§¸¶ÞáL¤·Íø­íñï³Ö¡¼ÅâÅ¬ÉC¥rÔo¹¼°Ððó¨öÊr¡¼¤Â¦FÍðËÒäó³Ï«fÐéÐæ­æãÇ¶Ñ¹»áB¡¼¾°¡¼ªÉ¡¼¤±ÉSÉRÉeÉh¡¼¥QÜº¥öÉ·Ê_É®­Î³É¥ê¦î¦ðÊa§ñ§H§F",
"Êc¦ï¡¼¦÷Ë¸Ë¹¨ÝËº¨Ô¨Ü¨Û¨Ù¾«Ë³»úËÆ¾©ÅkÄ×ÍÞ«ZÍãÍå«M«S­Ä­Å°´­ÖÐÓ°¿¡¼­Ø­ÚÐ×­¾­Ã­Ðàó°³°ºÔU°¹¶ÍÜ¼Ål¾ªõÀÜ¿¹¯äê¹°àúàð¹­äëäîÉiÉøÊeÜÂ«[ï¶¡¼÷@¤¼´SÆdïUöØÄÜ¡¼«mÐ±°Ëàí¦g¨á¡¼«^­½³O×ÀÁ¶ùC¸Ï¸[¾ÆòÝÃ½¡¼É¼¨æËÎ",
"¡¼¡¼¶ï­ß¡¼°P°R°SðÝÛÖ³[µþ¶F¶C¶@¡¼ÛßàFàLàG¸×¸ÙàM¸á¸à½Øë¡àH»¦»¢»¥äMçÔçØ½Ó½ÛçÜ½Ô½Ù¿Û¿Ïë¦¿Öë§¿Ù¿Ü¿Ú¿Í¿Ôë«ÂÓÆmî¢î°ÁÄÂÖ÷VòûÃ×ÃÔù©Ä¸Æ@¡¼Î¯¡¼ÊV¦é¨À¨ÁÍÙÍÚ«@°¤ÐÂÔFÜ¡³µ¶«³²Ü~¶ªàÔîõÊRÊTñKÊQà©Ë¨ÍÔÍÖªõ¿ó",
"ªóÍ×Ó÷Ð»Ð¼ë×¡¼Ð½ÜPÅ°°rÓüÓûÓú×ï×è¶nÜRäk»Âäh¾IèTÁÝôáöZ¯ì«·äô§WÊo¨ðÐø¡¼Ôm¼E­îÀèôw¡¼¡¼¡¼ÔJ¡¼¥¯¯cÐWÊ¬°î¡¼¹ÑéO¾ÃÀ¤¦f¦d¡¼¦`ÂRÉÈ¦eÃc§¦¡¼©X¡¼Ëõñö©\\ËûÌ@ËôËøËüÔÁÎSÎTÜåÔº¡¼¡¼«²«­ÑL¶ö³úÜäÑMÑRÔ²¡¼Ô·°ñ¡¼",
"Ô¸ÔËÔµÔ´Ô³Ø¢Ø¡¡¼³ûÜí¡¼á[áV¡¼¼UÄÉÅgÅt¡¼ÊMÊNËzË¡Í¿Ë£Ë|Ë}ëRªÜÍ´ªåªèªçô¾¡¼­UÍ¶ªéÍº³AµççvÍÁÍ¾ÍÀ¡¼ªß¡¼­RÍÃÐw­[¡¼Ð¡ô¸Ðn­`Ðu­\\¡¼ÐzÐ{­dçr¡¼­g¶÷ÞrÐ¢ÐqÓ}ÓwêþçnÓ¥²÷Ó¦¯õ¯ü×lëLÓ¬¯öÓ®¯þîP¯û¯úÂÉÓtÐrÓsººâl",
"¡¼Ó£ð°¡¼»^ßÒ¡¼¡¼²òãÂ¸±²û×m²ù¡¼»Y²þ¡¼×g×hëO²ý²ñ²ð×[Åa¡¼µ×ÛmÛoÛpÔ»¡¼µÖÛnµàÛu¡¼µãÛ{Û|µèµéÛyµÑµÒÛ^Û¥µÕÛ`¿¢µÝÛr¡¼ß±ß¸ß¹ß»ëA¡¼ßÂëDßÄ¸°¸¶¸´ß¬çoßÕ¸©¸µã¸ã¹ã½ÅZ¡¼»_»c»Uã°÷ðã®ã¶ã·ã¬¡¼î@ç\\¿_¡¼çuõýçTÄ©",
"êøçM½¶çd¿·¿¸¿¹ëB¿¿îDê{¿»ô¿íûíüÁ©Á¨íõîRÃÁÁ£îQÂÊð¸ÂÈÄö¡¼òÔô¹õøôÁõü¡¼÷ó¤{«ÙÉË¹ÝÐU«³®O®N°Ì¤qÉÕ§¼Àª¡¼±¿áÞÌ½Ì¹©é©í«úå¹ÎßÑºÑ»Ñ¸ÕmÙ^±º±ÌÕqºQÕy±ÅÕh±ÊÕzáèÙ`¡¼Ù]¼ÃÙg¡¼ÙU´¬´}ÙdïÒÝ®Ý¶Ý¸Ý}â^Ý«ÝºáçôLºTå¯",
"ºPÂ^ï×¼ÁõÍ¡¼é¦é¤ììÀÂòE÷Ýøï¤|ÊÖ¡¼·I¡¼¥w¼T¥n¥o¥{¦\\¡¼¦[¡¼åFÅmÊyñò§c¡¼Ðù¡¼¡¼¡¼Ëß¡¼©E©KËï©NÀ{©F©LËç¡¼¡¼Íü«{¡¼èý«¨«xäù¹ÍÎM¡¼éA«¦«©¡¼éD¡¼ìÁ«§«}¡¼¾ºÍþÎNáMÐô¼G®C­øÐõÜÔ¡¼®DÐü®AÔw¹ÉØoØp¡¼ÄÚ°ç°Þ¡¼Ôu¡¼",
"­ò°ÜÔqÔr¡¼°æÔ|°ã³ãÜÖ³ä³í¡¼ØnØq³ç³îÜÛØf³×¶Ø¹ÆôA³á³ñ¡¼¹È¶è¹Ê¶ßÄÙ¡¼ÜÒ¶ÛÜÐÜÓ¶â¶çÜÝ¾¼ÜÌÜÞ¶Ù¡¼¶áÅ¯¡¼¹ËáIáNÄX¡¼¹¾¹¿áG¡¼äþ¼I¼PåD¡¼¾¾¾²ÂPäø¡¼ìÃ¾¶¾»¾³¡¼¡¼À}ìÀ¡¼øî¡¼¦_ÉÆÔ¬§zËñ«ª®FÔ«°ëéG´WÌoÌn©®ìÛá²¹ö",
"±cØò¹÷¹ó¡¼¼n§ÄÉ×ÊÀ§Á¹òÊÂ®s¡¼§Â´P¡¼Ì^Ìe¡¼Ìa©¦©§Ìc¡¼©¢éa«ÐåiÎ}±WåcÔû±]ÔüÕD±\\Ôô±S±UÀ¯¡¼´QØæÝRØã·Dá¨ØÛØÝÝO·C¡¼á£åb¼jÁÇìÚÅqÉL§ÏÌu«à«â«á±t±p±u´aÝd¼xéuÅü¡¼¡¼É¦ÊCÂx¡¼ËcËeª­¡¼ÍaÏÀêa¬¼Þ¬Ò¥¯XÒªÒ¨ê`Ò¤",
"Ò©Öa²tÅzÖeÖiÖ`ônÚp¡¼µT¡¼¡¼Úqº¼âË¼ûæyê^íeõÝ¦ß¹Ù¶¸¹Û¡¼¡¼ïO¶»ñ­¶¹Ü®¶½¹~»èèÁ¾lÀ_¡¼ÃIó±ó¯ÄD¡¼õW¡¼ÉyåuÊÍ©´Îº«ÖÕI±g±hÕK½éá¼á¶åséréoÁt¡¼É{¦¤Äb¼­ÊÛáÓÊÝÊÞ·Z±£·[§ØÊÙ§×Ì|©ÅÌ{©Í©ÂÌ©©Ë©ÌÌ¢é}©ÉºEìæ´l·_ÎË",
"«ñÙ@®¯®ªáÇÑ§Ñ¨Ñ¥®­Ñª´g±¢Õ^Õ\\±¦±¨±«±|·Yå¦´j´h´m´s´pÝhÝgºH¼©¼¬¼¥¡¼¾ÏÃj©½ño­¬ØEÁò¶£¶{Üzök¾[è§ùÄè¦ìHìK¡¼ìLìNìFîñÁðÂóÂõÂöõE¡¼¡¼©Ï¡¼ÉýÉúÉüõÓ¨J¨N¨\\¨P¨Q¡¼¨X¨Z¨YÙìÌøÌôÌõò]Ãyªtªr¡¼ª~ª}ïöÌðÌñªbªlª{®ù",
"¬§¬¨¬{¯HÙþÏ§ÏwÏx¬­¬®éø¬«¬¬ÏzÂsâq¼ñÏvÒPÒOÕéæ\\ÒU®þ¯K¡¼ÒWÒZÒF²Z²N²X²SÂp²gÕí¿I²hÕó²FÂnÕáÕñ²RÙñ´óµBÚGÞYµGâ©ÚK´æ´è´ìµDùÐÞL·ÂõÔâ¥ïï·Á·ÌÞP¡¼ÞTæ_·ÍÞXÞF·¼ÞHæCò^Ãt¡¼º¨â£ºªâ¡Äkïõº¬âuºxæAæ@æB¼èæL¼à¼ëÃu",
"êA¿C¿F¿G¾üÀáÀä¡¼ÀÚÀÞÃvòcÃsôeô\\ø¯Åô¡¼ÉsÌXÌW«É®fÚ¬ÄÊºS¹í¼dër¾Èî¿îª¡¼ÍÎÍÑ­~Ðµ­£Ââ­{³w­¤°mÓï×ãÅÝ×ä³p³|×ç¶f¶jÜMÜOà¡¹Nà}¹I¾C»¸»½»¿¾æ¿îÁØÁÛÂäÂãÃå¡¼±kÎ½ØôÉu«¤®jÔó´Gá¢À«ÄóÑy©¸«Ú×X´]÷§¡¼¦q¦m§°¼a¹á§­",
"Êµ©nØµ§¬§±©qÌH©o©k©cÔÕ¼cÎgöÜ«»«¹¡¼®[®\\´E¼_®P®X®U°þÔÑ±DÔÐ±@±A¼`¡¼¶þ´D´@Ø¸¶üár·BéTÀ§Ü÷áu¹äéR¹â¹ß¹ãák¼^éQéXìÐÀ¨Ä\\ÉÔ¡¼§·ÌV´F¤m¤nÌUèÊ¾o¾tõ_Åæ¾qèÎÅ»÷~ÀcÆzñ¯ñ²ñ¶ö|õcÄEö}õaõbÅYö{÷|Ækù³¡¼¬ú¬ô¬øÐKõç",
"¯Æ¯ÄÓVÖæ²Ø²Ù¿¨²Ñ²Ò¡¼¡¼Úûµ¼ßXß`ßWºðºöãn¡¼ãl½xºþãqãeºíºý½yæç½{½zðræëæìæíêØæè¿§¿¦êÐ¿¥íÐ¿~¿¡Ä}ÁeÁgÁ]Á[ÁbõéÂ·Â¹¡¼ô­ò²ò´ù@¡¼½B¡¼Ír°oÊE¿YÞ³Íjª³ª²ÏÈÄn¬¿¬Å¬Ä¡¼ÏÉÒ­Ò¬¹z²xÒ²Ò°¯_Ã¢·éæ£µX·ëµaµ[µbÚ|ÚzÚ{",
"µ`Ú¡·è·ìÞ¶·å·êÀõºÁ½@¿XÄí½Aæ¦æ¢¼ý¿\\ÀöÀóíiÂzÅÐôoñ¤ó¥ÃüËB¨@§ûËCâYôUªJªWªHÌÙ¡¼ªSÙ³¼×±úªDªIªVÏUÀÍÏCôS¬^¬iôV¬jÏJ¬cÏL¬l±÷Ïa¬e¬kòRÎûì÷ÑÜÑÝÙ²¾øÑè·©ÑéâN±òÑë¡¼¾ì®ìÀÌ®å÷á¡¼ÑÛ®Ý±ëÕÀÕ¾ÕÁ±êÕÄÄç´ØÙÈÃpåÞ´Í",
"÷âÝÞÙÊ¼ÍÝÔ´ÐÙ¹ÝÎÝÒ·£ÝÓ·¯ÆV·ª¡¼¡¼ÝßÝàºlÄhÃqâAõÑÝÉ·°·­ºdâIºfºgºkâRáüº`âTÂbº_òLâJåÓÀÎ¼ØåÌåèòUåÚ¾ñéÄÀÒéÑéÈ¾öìþÃr¾êéÊ¾ïòXíDÀÑìõÀÐ¡¼·ß¡¼ª\\Ïe¼ÜÏfâfÀÔÕÜéãÝûÂléâ°b³m¡¼¶aøGÜ@¶cÜH¡¼÷eÛþ¸ý¸þàyàx»³½û½þ",
"½ù½ý¿êñFÃá¡¼Ì±á×±®´u·a·`ÝuÝváÖ»N¿^Ò¾ÞÀírípðI¡¼ÉîÉíÊø©þ¾èªXÌÊ©ý©ûÍR¬TÎõÎö¬RÎëÎî¯ÏÑÔ¾ç®Ð®Ë·uÕª¡¼´¾·yÝÀÀÇº\\é´ïÛÂ`ÄfÄä¶NÛêÛè¶Mðô¸í¸ðöR»¬çìäS¡¼çîÁÌÛÑÁ»äD÷S¿ÌîzÂÑòóÏ½¡¼¦É¡¼¬ºÖ\\Ö_µQÚlÞ¥¡¼º¹®²ÕfÙT",
"áîÀ¼¬þ¡¼Ùå··å÷Þ@¾ûò[éèöçÉ~É÷ËIËJÏl´ã®ôÕßºr¡¼±Õ¡¼Ã|·Þ¼ø¬¸ç~¦G¡¼Ëx¨w¡¼ÌÒ¡¼ªÐªÒÍ°ªÔ¡¼Äg¡¼¡¼Ä¤­KÐ[«`Ð_ÐgÐeÎú­O×H¯Ö¯Û¯ÚÁz¡¼¡¼¯â®Ó¡¼³bß¢×L×K×E¡¼¡¼µËµÌµÍ¡¼¡¼¸xßsßv¡¼ã¦¡¼¡¼ÜæÜù»J»MÂÁ¼ðæý¡¼íêÂaíëíè",
"¡¼êéÂjÕØÙÚÝ÷Ýõ¾ùäÍ»ãÁüÄBöt¡¼¡¼ÝbÁÔî}´´ø~Äã©óÑÏÑÑÑÐ±Ü±ÝÙ~ºY·ÕÞm¿L¡¼¡¼¡¼Ï®¬¯Ï±êM¯LÖQÖU¿TÚZÚ]¡¼·Ô·Û¡¼Þs¡¼Þt¡¼¡¼æræi¼÷æfÀîêOÀæïûõÚÆy¡¼Âv·Ö¿Q©ÑÌ²ÎÓ±¯´v¡¼ªÁ¬æ¬çÒçÒéÒê¯®ïä¯­¯¨ºÕÖ½¸RÁIâùæËÁHÅ¡Ê×ÊØ",
"ïÈÑ|Ñ}Ñ~Ñ¡®~®¡áÃ·^·]¼|¾ÍévÀ·ÂVùº¡¼¦ÖÌîíOÙçÁFÍzâîÏñÚÏ¡¼Ïë¬H¯¢¡¼¯|¡¼Ärõâ¯¤¡¼¯¡ÒÚÒÙÒâ²ºÚÉÚÆí¦Ö¹Ö»¡¼Ö¸¡¼¿l¸PÞåÞäê§ÞìºÔâë¡¼âóæÆ¡¼æÊ¿kíªí«ÁEðXô}ò¤ò¡÷ÎÜ°ï°óõÍwÏâ¡¼¬Ú¬àÏàÒÖÒ×ÒÕÖª¡¼Ö²²¶·ýÂ¥Ú»¡¼ÞÝ¸E",
"¸F¸DºÍæ¼ºÌâç½O½P¿g¿eÀýízÂ¢ËmÍq¬Ê¬ËÏÛÒÁÚ®ÞÄ¡¼ÐMÓ\\¯ËÛàßjò¼¡¼¿©Åùíã¯r¿d÷ø¡¼ÐÁÐÀ°z°xÔBØA³©×üëê³¦×ý¡¼Üg¹d¶z¶xÜbÜpÜoÜdÜjà±à²¹Wà³¡¼¹Z¹Yàµà»àº¹fÅàà°¹bà®¹cà·¹eÅM¾Rä{äzä}ä¨èhÄÂ¡¼ÅL¡¼ä¡ñZ»Ëèoä·ôó»Íä¦",
"ójä¢¿þä£à¶ôç»Ïä§ôùëäèiÃô¡¼¾Yèpèr¾Vèn¡¼¡¼¡¼ècèjèvëèëá¡¼ëæ¡¼ëéÀCÀD¡¼¡¼ëßëàÀEÁæîÒîÖÁîîÐñ\\Áì¡¼ÃóÃò¡¼¡¼óhÂðÅO¡¼ñ^ÂïñS÷gÃðÃíÃîÃñó`ÃëóaÃéôì¡¼ôõ¡¼ôèùSôê¡¼ófôñ÷iÅNö^¡¼ÅßÁéÏèÚÄ¹nÏùÒñ¯°Òí¡¼´RÚØÚÖ¸\\¸Z",
"æÒ½^Â¨ÂHÃLöø¬Ô²®µqÞÕíxÒ¼²}¨i¹§»ðèé¾}Àlóðù·ì©ì®Åîï{÷Áï~ï¢Æ}ñÐùÏÃ[ñÙøpñÏÄM¡¼ÄOóíÄLõ|õ§¡¼¡¼¡¼Åcö´ÆxÅÂ÷ºøcøkøløf¡¼ÆOÆ|¡¼ËoðKÂ~ª·¡¼¬Ð¯i¡¼¯n¡¼¡¼ÒÃ¡¼¯m¡¼²­µiÀ÷Ú²ÚµíwÚ¯ÞÉ·óÞÌ·õÞÏ·ïívâÜæ°âßæ¯¡¼âÝæ±",
"¡¼êp½I½C¡¼êlêsöôêqítÅ}êo¡¼Äî¡¼ðJÂ}Åö¡¼ÖöÚÜÍ¥ªÆÏþÒö¯·²ÀÄu¸^ãLãJê²æÕ¡¼Ð®ÓÔ°MÓ×°L×µÃËÛËÛÊÛÏîrßôòððÙã÷»uãü»tãúä@¿ÊçÈ½ÈÁ¹½ÊÄ°¿ÉÁ·îuôËùK¥Ô­Eâáµr¬á¦ÔÐTÓf²à¡¼¡¼¡¼½¢íçêæ¿®¡¼µÀÍª×C²âô²µÁð|Ámµ÷Ü¬àààÞ",
"¾e¾g¡¼è¸ÀXÃEÃFù®õOó¨ÅV¡¼ÆI¡¼°@ÍÈðÊòã­kÐ¨­jÓºÓ¼ÓÂ¸ÃÓÌÓÈ°G°B°C°E³F³G³HÄ÷×¥×¤³K³L³MòÞ×«Û¼ßæÂÌµíëkµñ¸»µòôÅµëÛ±Û¿¸Â¸½ßê¸¼¸ÄßïßìãÖ»fãÛ»hãÚãòãâÁ´»iãë»m»l»d½¸»g¡¼ôÆç¼½»¡¼½Áç¸¡¼½Âç¢Á²ç£½¿çºë^îg¡¼Á¯",
"Á°ë`ëgîZë]¿ÀÁ±ðÁî]î_Á®ÁµðÇînÁ­Á¬îið¾ðÀÂÏ¡¼ôÉôÈÃÊòçöBÄùÅûø¾¦ÎÄ¢Ájíá¯çªÇ¬òÓD¿wÓ@¸cÓEÖ×ÓCÖÌÖÛÖÔ²Æ²ÈÖÖ²ÁÖÎÖÑÖÒøû²ÇÚåíÃÚæºáÚâºå¸a¸b¡¼¡¼ßKßNãRí½æ×ºææÙºãöûãXÂ°ãO¡¼Â­½eÂ±½h½jêºê½ê¼¿{êÁÁPÁN¡¼í»ø¸íÂ",
"ðeÂ¯ðhÃ°Å£Ã³ªØÓp²êÛW¯åÓÐÐi­QòÃ¡¼Óq¯ê¯é×S÷F×T×V¡¼ß¥ß¤»SçFíñð¢ô¶ÓÚ¸Í³P¸Ê¸ÆÃÎÖôßmßn½~æó¿ª¡¼®ÅÓJ¡¼¡¼ÚèÚçßTã`ºêÁX¡¼æá¡¼æàæßêÉíÏ¦áº[¬ý²Þµ¿ã}»Bæù½¡¿­Ák¦ÍíÞãuãvíÙùA¾¢ÄT­vÛíàdà^ùo³i½êÓÞ³a­ªÓþÔ@ÔAÜ^",
"Ü`Ü]¡¼¹Uà­Æoùqäs»Æät¡¼è[ëÙëÛëÚîÆÁÞñRó_ÃçñQôäÄ¿ÅH¨¨öÉÄ»àrä`ÂÙñDÓå×Ù×Ö³lî¾ÛôÛú¶\\÷`¶YÛö¶_¶`àiÃßÂÞàn÷_ÅE¸øäWä[è@½ï½óÅ®ç÷çôÅ­¡¼ëÀ¡¼¿æëÄ¿âÁÎëÅ¿äÆ\\ÂÚÁÑ÷]ÃÝÃÚóSÃàÄ½Æn÷^÷aùpøÃË¤¶I¸çàZðñî·±Ø×ÆÂÒÛÔàC",
"ßýäHòõ¸äðçè°³¸ÆE¶²¾^Å´è®ÀPÀKÃùÆGÄÅÅµïµÄÔõ¾õ»ÅhÅiÅÅÅÆÆSàïï±ùe«AÔG¹màÕ»ÜÂ£øAä©ÆqètÃõîÞólîÜ¡¼øÊ¾{èÛø[¡¼¡¼Æt¿qì{ÆMì|¡¼ïjÂCïlù\\ÂBóÐøXñÇùÎÅ¿÷®ö­÷²ÃXÃTñÃÃVÄJóÇóÈóÖóËÄI¡¼óÍóÎÄK¡¼óÏ¡¼õkÆsÄÏõnõv¡¼¡¼",
"÷´Å_ö®Å`ö¯÷¯ÅÀ÷«ÅÁ¡¼¡¼ÅíÅëøWø×»Þ»ßÅ¶¡¼ìVÆiñ|Âý¡¼¡¼äÚ»ë¾uö¼¡¼¡¼ÀfÃNñ¹Å\\óÁÆbøÔÅê¾yèÙÆLÃRïiÃSÅ^ÅWÅäÃKÅ¹÷vÔI¹¦»ì¾wèÔÀgÀhìpñ»¡¼ÆKøUÆc»ò¾£íÝ¹¨ì±ì¯ÂGÄQÃïÅeÅïÂLÂJÂKÃ\\ñà¡¼Æuõ¶õ´øvÅfï´Ã^ÄÓÅÄø{ì¸ÂM¡¼"
});

string *b5=({
"¡¡£¬¡¢¡££®£®£»£º£¿£¡¡Ã¡­¡§£¬¡¢¡¤¡¤£»£º£¿£¡£ü¡õ£ü¡õ£ü£ß¡õ¡õ£¨£©£¨£©£û£ý£û£ý¡²¡³¡²¡³¡¾¡¿¡¾¡¿¡¶¡·¡¶¡·¡´¡µ£Þ¡µ¡¸¡¹¡¸¡¹¡º¡»¡º¡»£¨£©£û£ý£Û£Ý¡®¡¯¡°¡±£¢¡å£à£§£££¦£ª¡ù¡ì¡¨¡ð¡ñ¡÷¡ø¡ò¡î¡ï¡ó¡ô¡õ¡ö¡õ¡õ¡õ¡õ£þ¡õ£ß¡õ¡õ¡õ¡õ¡õ¡õ¡õ£££¦£ª£«£­¡Á¡Â¡À¡Ì£¼£¾£½¡Ü¡Ý¡Ù¡Þ¡Ö¡Ô£«£­£¼£¾£½¡«¡É¡È¡õ¡Ï¡õ¡õ¡õ¡õ¡Ò¡Ó¡ß¡à¡â¡á¡õ¡Ñ¡ü¡ý¡û¡ú¡õ¡õ¡õ¡õ¡¬¡õ£¯",
"£Ü¡õ¡õ¡ç¡õ¡õ¡é¡ê£¥£À¡æ¡õ¡ç£¥£À¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡ã¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ©à©Ø©Ð©È©À¡õ¡ª©¦¡õ©°©´©¸©¼©°©´©¸©¼¡þ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ£°£±£²£³£´£µ£¶£·£¸£¹¢ñ¢ò¢ó¢ô¢õ¢ö¢÷¢ø¢ù¢ú¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ£Á£Â£Ã£Ä£Å£Æ£Ç£È£É£Ê£Ë£Ì£Í£Î£Ï£Ð£Ñ£Ò£Ó£Ô£Õ£Ö£×£Ø£Ù£Ú£á£â£ã£ä£å£æ£ç£è£é£ê£ë£ì£í£î£ï£ð£ñ£ò£ó£ô£õ£ö",
"£÷£ø£ù£ú¦¡¦¢¦£¦¤¦¥¦¦¦§¦¨¦©¦ª¦«¦¬¦­¦®¦¯¦°¦±¦²¦³¦´¦µ¦¶¦·¦¸¦Á¦Â¦Ã¦Ä¦Å¦Æ¦Ç¦È¦É¦Ê¦Ë¦Ì¦Í¦Î¦Ï¦Ð¦Ñ¦Ò¦Ó¦Ô¦Õ¦Ö¦×¦Ø¨Å¨Æ¨Ç¨È¨É¨Ê¨Ë¨Ì¨Í¨Î¨Ï¨Ð¨Ñ¨Ò¨Ó¨Ô¨Õ¨Ö¨×¨Ø¨Ù¨Ú¨Û¨Ü¨Ý¨Þ¨ß¨à¨á¨â¨ã¨ä¨å¨æ¨ç¨è¨é¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"Ò»ÒÒ¶¡ÆßÄË¾ÅÁË¶þÈË¶ùÈë°Ë¼¸µ¶µóÁ¦Ø°Ê®²·ÓÖÈþÏÂÕÉÉÏÑ¾Íè·²¾ÃÃ´Ò²ÆòÓÚÍöØ£ÈÐÉ×Ç§²æ¿ÚÍÁÊ¿Ï¦´óÅ®×ÓæÝæÞ´çÐ¡ÞÌÊ¬É½´¨¹¤¼ºÒÑËÈ½í¸ÉÞÃß®¹­²Å³óØ¤²»ÖÐ·áµ¤Ö®ÒüÓèÔÆ¾®»¥Îå¿ºÈÊÊ²ØêÆÍ³ðÈÔ½ñ½éØÆÔªÔÊÄÚÁùÙâ¹«ÈßÐ×·ÖÇÐØ×ÔÈ¹´Îð»¯Æ¥ÎçÉýØ¦±å¶òÓÑ¼°·´ÈÉÌì·òÌ«Ø²¿×ÉÙÓÈ³ßÍÍ°Í»ÃØ¥µõÒýÐÄ¸ê»§ÊÖÔúÖ§ÎÄ¶·½ï·½ÈÕÔ»ÔÂÄ¾Ç·Ö¹´õÎã±ÈÃ«ÊÏË®»ð×¦¸¸Ø³Æ¬ÑÀÅ£È®Íõ±û",
"ÊÀØ§ÇÒÇðÖ÷Õ§·¦ºõÒÔ¸¶×ÐÊËËûÕÌ´úÁîÏÉØð³äÐÖÈ½²á¶¬°¼³öÍ¹¿¯¼Ó¹¦°ü´Ò±±ÔÑÇª°ë»Ü¿¨Õ¼Ã®Ø´È¥¿É¹ÅÓÒÕÙ¶£ßµß¶µðË¾ØÏ½ÐÁíÖ»Ê·ß³Ì¨¾ä°Èß·ËÄÇôÍâÑëÊ§Å«ÄÌÔÐËüÄá¾ÞÇÉ×óÊÐ²¼Æ½Ó×ÛÍºë¸¥±ØÎì´òÈÓ°ÇÆË³âµ©Êõ±¾Î´Ä©ÔýÕýÄ¸ÃñØµÓÀÖ­Í¡·º·¸ÐþÓñ¹ÏÍß¸ÊÉúÓÃË¦ÌïÓÉ¼×Éêñâ°×Æ¤ÃóÄ¿Ã¬Ê¸Ê¯Ê¾ºÌÑ¨Á¢Ø©¶ªÆ¹ÅÒØÀØ¨½»Òàº¥·ÂØø»ïÒÁ·òÎé·¥ÐÝ·üÖÙ¼þÈÎÑöØò·ÝÆó¡õ¹âÐ×Õ×ÏÈÈ«",
"¹²ÔÙ±ùÁÐÐÌ»®ØØë¾ÁÓÐÙ¿ï½³Ó¡Î£¼ªÀôÍ¬µõÍÂÓõ´ç¸÷ÏòÃûºÏ³Ôºóßºß¸Òò»ØàîÛÚµØÔÚ¹çÛØÛÝÛ×Ùí¶àÒÄ¿äÍý¼éåúºÃËýÈçåù×Ö´æÓîÊØÕ¬°²ËÂ¼âÒÙÖÝ·«²¢ÄêÊ½³ÚÃ¦ââÈÖÐçÊù³É¿Û¿¸ÍÐÊÕÔçÖ¼Ñ®ÐñÇúÒ·ÓÐÐàÆÓÖì¶ä´Î´ËËÀÄÊÈêº¹ÎÛ½­³ØÏ«ÉÇÎÛÑ´¡õ·º»ÒÄ²êò°ÙÖñÃ×ôéó¾ÑòÓðÀÏ¿¼¶øñç¶úí²ÈâÀß¼¡³¼×ÔÖÁ¾ÊÉàâ¶ÖÛôÞÉ«°¬³æÑªÐÐÒÂÎ÷Úä´®ºàÎ»×¡ØùÙ¢Øú°é·ðºÎ¹À×ôÓÓÙ¤ËÅÉìµèÕ¼ËÆµ«Ó¶",
"×÷Äã²®µÍÁæÓàØþ²¼Øý¶Ò¿ËÃâ±øÒ±Àä±ðÅÐÀûÉ¾ÅÙ½ÙÖúÅ¬Û¾Ï»¼´ÂÑÁß¿ÔÍÌÎá·ñ¡õ°É´ôßÀÎâ³ÊÂÀ¾ý·Ô¸æ´µÎÇÎüË±³³ÄÅ·ÍºðÑ½Ö¨º¬Ò÷Ìý´ÑÀ§¶Úàñ·»¿ÓÖ·Ì®¾ù¿²»ø×ø»µÛß×³¼Ð×±¶Ê·Áæ¤åþÃîÑýåûæ¥¼ËÈÑÍ×Ð¢×ÎæÚØÃÍêËÎºêÞÎ¾ÖÆ¨ÄòÎ²áªá¯²íá§Î×Ï£Ðò±Ó´²Í¢ÅªµÜÍ®ÐÎáÝÒÛÍü¼ÉÖ¾ÈÌ³À¿ìâîâì½äÎÒ³­¿¹¶¶¼¼·ö¾ñÅ¤°Ñ¶óÕÒÅú°âÊã³¶ÕÛ°çÍ¶×¥ÒÖ¡õ¸Ä¹¥Øüºµ¸üÊøÀîÐÓ²Ä´å¶ÅÕÈè½É¼¸Ë¸Ü",
"è¼¡õ²½Ã¿Çó¹¯É³ÇßÉò³ÁãäÅæÍô¾öãåÌ­ãçãè³åÃ»ÆûÎÖ¼³·Úãêãìãë¡õãæ¡õÒÊÔî×ÆÔÖ¾ÄÀÎÄµËüµÒ¿ñ¾Áð®¸¦ÄÐµéÔí¶¢ÒÓË½ÐãÍº¾¿Ïµº±Ð¤ëÁ¸ÎÖâ¸Ø¶ÇÓýÁ¼Ã¢ÓóÉÖ¼û½ÇÑÔ¹È¶¹õ¹±´³à×ß×ãÉí³µÐÁ³½ÓØ¡õÑ¸ÆùÑ²ÒØÐÏÐ°°îÄÇÓÏ¡õÀï·ÀÈîÚåÚæ¡õ²¢¹ÔÈéÊÂÐ©ÑÇÏí¾©ÑðÒÀÊÌ¼ÑÊ¹ÀÐ¹©ÀýÀ´Ù©°Û²¢³ÞÅåÙ¬ÂØÙ«ÙªÙ§¡õÍÃ¶ùÙîÁ½¾ßÆäµäÙýº¯¿ÌÈ¯Ë¢´Ìµ½¹ÎÖÆ¶çÛÀ¡õ×äÐ­×¿±°ØÔ¾íÐ¶ÐôÈ¡ÊåÊÜÎ¶ºÇ",
"¿§ÅÞ¹¾¾×ÉëßÈßÍÖäÅØºô¸ÀßÉßÎºÍßËÄØÖÜÕ¦Ãü¾Ì¹ÌÀ¬¿ÀÆºÛáÆÂÌ¹À¤ÛåÒ¹·îÆæÄÎÑÙ±¼æªÆÞÎ¯ÃÃÄÝ¹ÃÄ·½ãæ©Ê¼ÐÕæ¢æ¨Äãæ¦¡õÃÏ¹Â¼¾×Ú¶¨¹ÙÒËÖæÍðÉÐÇü¾Ó½ìáº¸Ô°¶ÑÒá¶á·ÔÀÁ±ÖãÌûÅÁ²¯àûÐÒ¸ýµê¸®µ×âÒÑÓÏÒ»¡åóÍùÕ÷·ð±ËãÃÖÒºöÄî·ÞâóÕúÇÓâð²À¹ÖÅÂâùÐÔâõâöâò»òãÞ·¿ìåËù³ÐÀ­°èÖôÃò·÷Ä¨¾ÜÕÐÅûÍØ°ÎÅ×ÄéÅê³éÑº¹Õ×¾Ä´ÅÄµÖÞÕ±§¾ÐÍÏÞÖ²ðÌ§Áà·Å¸«ì¶ÍúÎôÒ×²ýÀ¥°ºÃ÷êÀ»èê¿ê»",
"Éý·þÅóº¼èÊÕí¶«¹ûèÃèËèÁÖ¦ÁÖ±­½Ü°åÍ÷ËÉÎöèÆÃ¶¡õèÌèÂê½ÐÀÎäÆçéâÃ¥·ÕÆü×¢Ó¾ãûÃÚÄàºÓ¹ÁÕ´ÕÓ²¨Ä­·¨ãü·ÐÐ¹ÓÍ¿ö¾ÚãôÇöãóÑØÖÎÅÝ·º²´¡õãý¡õã÷ãö¿»Ñ×³´´¶ÖËÅÀÕù°Ö°æÄÁÎï×´áò¾Ñ¹·ºüÍæçåçäÃµ¡õ¡õðÞ¸í¾ÎµÄÓÛÃ¤Ö±ÖªÎùÉçìëÆî±ü¡õ¿Õñ·óÃ¾ÀØèÇ¼ØÂÕß·Î·ÊÖ«ëÅ¹ÉëÆ¼çëÈ·¾¿ÏÎÔô§Éá·¼Ö¥Ü½°ÅÑ¿ÜÏÇÛ»¨·Ò½æÐ¾Ü¿¡õÜÁÜÀÜÆ»¢Ê­³õ±íÔþÓ­·µ½üÉÛÛ¡ÇñÚý²É½ð³¤ÃÅ¸·ÍÓ°¢×è¸½",
"Úéö¿ÓêÇà·ÇØ½Í¤ÁÁÐÅÇÖºî±ãÏÀÙ¸ÇÎ±£´ÙÂÂ·ýÙ¹¿¡Ë×ÎêÀþ¶íÏµÙµÙÞÓá¾ÖÙðÃ°ëÐ¹ÚÉ²ÌêÏ÷Ç°ØÝ¿ËÔòÓÂÃã²ª¾¢ÙéÄÏÈ´ºñÅÑÒ§°§×É°¥ÔÕÏÌß×¿ÈÍÛßÓÑÊßäÆ·ºå¹þ¿©åëÔÛßÝßãßÖßÞàó´¹ÐÍÛóÔ«¹¸³Ç¿åÛòÞÈÆõ×à¿üÛ¼½ªæ°×Ëæ¯ÒÌÍÞÀÑÖ¶Ò¦¼éÍþÒöº¢Ðû»ÂÊÒ¿Íå¶·âÊºÆÁ¡õÎÝÖÅá¼ÏïµÛË§¡õÓÄâÔ¶È½¨ÞÄåôÑåºÜ´ý»²ÂÉáßáááàÅ­Ë¼µ¡¼±ÔõÔ¹»ÐÇ¡ºÞ»ÖºãÊÑÌñ¶²ã¡Ðô±â°ÝÍÚ°´Æ´ÊÃ³ÖÞ××§Ö¸¹°¿½",
"ÕüÀ¨Ê°Ë©Ìô¹ÒÕþ¹Êí½Ê©¼È´ºÕÑÓ³ÃÁÊÇÐÇ×òêÅ¡õêÂÊÁÈ¾ÖùÈáÄ³¼í¼Ü¿ÝÕ¤èÑ¿Â±ú¸Ì¡õèÖ²éèÛ°Ø×õÁøèÒèÔèÜèØÆâÍáÑê´ù¶Î¶¾Åþ·úÈªÑóÖÞºéÁ÷½òä£¶ý¶´Ï´»îÇ¢ÅÉÐÚÂå±Ãä¡ä¢¡õ¡õä¬ä­ä©äªìÅÎª±þ¾æ¾¼Ì¿Õ¨ÅÚ¡õë¼Éüêô¡õá÷ºÝ½ÆçèÉº²£ÁáÕäçêçéÉõ±ÂÎ·½çî°î±Òß°Ì½ê¡õðà¹ï½Ô»Êð§Ó¯Åè¡õÖÑÊ¡íïÏàÃ¼¿´¶ÜÅÎíðñæÉ°ÑÐÆö¿³ìììíÆí¡õÓíØ®¿ÆÃëÇï´©Í»¸ÍóÄ×Ñæûºì¼ÍÈÒæüÔ¼æú¸×ÃÀôàë£",
"ÄÍË£×¨Ò®ÅÖñãÅßÎ¸¡õ±³ºúëÎÌ¥°ûØ·ëÕÖÂô®ÜÑ·¶Ã©ÜÄ¿Á¿àÇÑÈôÃ¯ÜÔÜÛÃçÓ¢×ÂÜÙÌ¦Ô·°úÜß¹¶±½ÜâÅ°ºçòµò³ÑÜÉÀÒª¡õ¼Æ¶©¸¼Õê¸º¸°ôñÅ¿¾ü¹ìÊöåÈÌöµÏåÄµüÆÈåÆåÊ½¼ÀÉÓô¡õÇõôúÖØãÅÏÞÂªÄ°½µÃæ¸ïÎ¤¾ÂÒôÒ³·ç·ÉÊ³Ê×Ïã³ËÙñÙÄ±¶·Â¸©¾ëÙÅÙºÙ»ÐÒÁ©Öµ½èÒÐµ¹ÃÇ°³Øö¾óÙÆ¾ã³«¸öºòÌÈÙ½ÐÞÙÁÄßÙÂÂ×²Ö¼æÔ©Ú¤¡õ¶³Áè×¼µòÆÊØàÌÞ¸Õ°þ·ËÇäÔ­ØÈÛÅÉÚÌÆÑäà¡ºß¸çÕÜËô²¸ßíÁ¨¿ÞÔ±°¦ÏøÄÄ",
"Å¶ßó´½ßìßñÆÔàô¹¡ÆÒÂñ°£¡õÏÄÌ×ÞÊÞÉæ¶ÄïÄÈ¾êÓéæ¸¼§Éïæ·Ãä¶ðæ²æ³Ëï¡õÔ×º¦¼ÒÑç¹¬ÏüÈÝå·ÉäÐ¼Õ¹åìÇÍÏ¿¾þÓø¶ë·åµº¡õá­²îÏ¯Ê¦¿âÍ¥×ùÈõÍ½¾¶Ðìí¦í§³Ü¿ÖË¡¹§¶÷Ï¢ÇÄÎòã¤º·»Úã©ÔÃã£ÉÈÈ­êüÄÃÉÓÐ®Õñ²¶ÎæÀ¦Äó×½Í¦¾èÍìÅ²´ì°¤º´°ÆÐ§ôÍÁÏÅÔÂÃÊ±½úêÌ»ÎÉ¹ÉÎ¡õêËÊéË·ëÞÀÊÐ£ºË°¸¿ò»¸¸ù¹ð½ÛèòÊáÀõ×ÀÉ£ÔÔ²ñÍ©èî¸ñÌÒÖêÎ¦Ë¨¡õèìÊâÑ³ÒóÆøÑõ°±º¤ë³Ì©ÀËÌéÏûãþÆÖ½þº£Õãä¸",
"¡õÉæ¸¡¿£Ô¡ºÆÓ¿¡õä¤Äù¡õä¹ìÈºæ¿¾ÀÓÁÒÎÚµùÌØÀÇÏÁ±·Àêáú¡õ°àÁðÅåÖé¡õçóÅÏÄ¶ÐóÛÎÁô¼²²¡Ö¢Æ£ðá¾ÒÌÛÕîðèðã¸Þ¡õÒæîÁ°»Ñ£ÕæÃßÕ£¾ØÅéÕèÔÒíÀÆÆÉéíÆí¾¡õíÄÅÚ¡õÓÓìôËî×æÉñ×£ìóìñ³Óï÷Ñí×âÇØÖÈÃØÕ­ñºÕ¾°ÊÐ¦·Û·ÄÉ´ÎÆÎÉËØË÷´¿Å¦ç¢¼¶ç¡ÄÉÖ½·×È±î¹¸á³áÎÌêÈÔÅ¸û°ÒºÄµ¢¹¢ë×Ö¬ÒÈÐ²ëÙëØ´àÐØ¸ìÂöÄÜ¼¹ëÝ¿è³ôô«Ò¨óÂº½ô³ô²°ãÛ»Ã£»ÄÀó¾£È×¼ö²ÝÒðÜîÜó×ÈÈã²èÜøÜ÷Üï´ÄÜõ",
"ò¯ÎÃò½ò¾Ôéò¿°öò¼ÑÁË¥ÖÔÔ¬ñÇñÅ¡õ¼ÇÚ¦ÌÖÚ§Ú¨Ñ¶ÍÐÑµÆý¡õ¡õÆñ²ò±ª²Æ¹±Æð¹ªÐùéí¡õÈèËÍÄæÃÔÍËÄË»ØÌÓ×·åË±Åçß¿¤ºÂÛ«¾ÆÅä×Ã¶¤ÕëîÈ¸ªîÇÉÁÔºÕó¶¸±ÝÉÂ³ýÚêÉýÖ»¼¢Âí¹Ç¸ß¶·Øª¹íÇ¬¡õÎ±Í£¼ÙÙÈÙ¼×öÎ°½¡Å¼ÙËÙÉÕì²àÍµÆ«Ù¿¡õ¡õ¶µÃá»Ë¼ô¸±ÀÕÎñ¿±¶¯ÙëÞË³×ÄäÇøØÒ²ÎÂüÉÌÅ¾À²×ÄÑÆ·È¿Ð°¡³ªà¢ÎÊßûÎ¨Æ¡ÄîÊÛà¨»£ÏÎà¦ßú¡õÈ¦¹úàöÓò¼áÛÑ¶Ñ²ºÛý»ùÌÃ¶ÂÖ´Åà¹»ÉÝÈ¢Â¦Íñ¸¾À·æ¹",
"æ½æ¾»éÆÅæ»Êë¿ÜÒú¼Ä¼ÅËÞÃÜÎ¾×¨½«ÍÀÌë¡õ³çáÇÆéáÈÑÂá¿À¥±À´ÞÂØáÅáÂ¸Ú³²³£´øÕÊá¡¿µÓ¹ÊüâÖâ×ÕÅÇ¿åç±ò²ÊµñµÃáã´ÓÅÇÓùáâáäÓÁ»¼Ï¤ÓÆÄúÍïã²µëÆàÇéã¬âêÏ§µ¿ã¯Ìèã°Î©¼Âã±¶ØÆÝê©ìèÂÓ¿Ø¾íÒ´Ì½½Ó½ÝÅõ¾ò´ëÞßÑÚµôÉ¨¹ÒÞÑÍÆÂÕÊÚÕõ²ÉÞäÅÅÌÍÏÆÄíÞæÉáÞà±Ö°½¾È½Ì°ÜÆôÃôÐðë·¡õÐ±õúÕ¶×åÐýìºì»ÖçÍíÎî³¿»Þ¡õ²Ü¡õÍûÁºÌÝÉÒè÷èó¡õÍ°¡õÎà¹£ÐµèèÆúËó°ðÃ·èÙÌõÀæèÉ¡õ¡õÓûÉ±",
"ºÁ¡õÇâÏÑÁ¹´¾äÈÒºµ­ÌÊÓÙÌíÇ³Çåä¿ÁÜÑÄÊçäÌäÁÑÍºÔ»ìÔ¨äÀÆàä¾º­ÀáÒùÌÔÂÙÉî»´¾»Ïý×Í¸¢´ãäÃäÆÅëÑÉº¸·éÏ©Ë¬Ç£Àç²ÂÃÍ²þâ£ÕøÂÊÀÅçðÇòÀíÏÖ¡õð­Æ¿´ÉÌð²úÂÔÆè±ÏÒìÊèÖÌºÛ´ÃÈ¬ðêð¨¿øºÐÊ¢¾ìÖÚÑÛ¿ôíøÌ÷ÁòÖìíÊÏéÆ±¼ÀÒÆÖÏñ»óÒ±¿µÑµÚ·ûóÏó×óÐÁ£´ÖÆÉ°íÏÒÍ³ÔúÉÜç¨ç©Ï¸Éð×éÀÛÖÕç¥ç¦²§ÐßÁçÒîôáÏ°ñêÁÄñö¸¬²±¡õÍÑ¡õ¡õ¡õô©¶æÏÏ²°´¬É¯Ý¸Ý·Ý©¼Ô¾¥Ã§ÄªÜì×¯Ý®ÀòÝ¬ºÉÝ¶Ý±",
"ÆÎÜÈ´¦±ëÉßÖûòÀòÁòÂÇùµ°òÆòÇòÈÊõÙòôÂ±»Ì»ÐäÅÛ´üÃÙ¹æ·ÃÑÈ¾÷Ú«ÐíÉèËÏ¶ïÐÀôùëà··Ôð¹á»õÌ°Æ¶ôöÉâÖºõÃéîÈíÕâåÐÍ¨¶ºÁ¬ËÙÊÅÖðåÉ³ÑÔìÍ¸·êåÑ¹äÍ¾²¿¹ù¶¼ÐïÒ°îÎ¿ÛµöîË¡õ·°±ÕÅãÁê³ÂÂ½ÒõÚðÌÕÏÝÚîÈ¸Ñ©ö§ÕÂ¾¹¶¥ÇêÓãÄñÂ±Â¹ÂóÂé¼Ò°ø¸µ±¸½Ü¿þØ÷É¡Ð§×î¿­¸îØÜ´´Ê£ÀÍÊ¤Ñ«²©ØÊà´¿¦ÐúÌäº°ºÈ´­Î¹Ï²É¥à¸À®à©à«Ôûµ¥à°ÍÙÓ´»½Ó÷ÇÇà¬à±ºí¡õà¹Î§Ò¢¿°³¡µÌÑß±¨±¤ÛöÜ©Ò¼ºøµì",
"æÃÃÄÐöÃ½æÂæ´æÜåîº®¸»Ô¢ÃÂ×ðÑ°¾ÍÇ¶á°áËïúÙã·ùÃ±Ö¡àø¼¸ÀÈ²ÞÏá¾ÇåöÅí¸´Ñ­áå»ó¶ñ±¯ÃÆ»Ýã«ã¶ÐÊãµ¶èâüã·¿®ÄÕã¹»ÌÓäã¸¡õêªìé³¸ÕÆÃè¼ð¿«ÈàÞñ×á²å´§ÌáÎÕÒ¾½Ò»Ó´·Ô®¾¾»»ÞðÑï±³³¨¶Ø¸ÒÉ¢°ßì³Ë¹ÆÕÎúÇç¾§¾°ÊîÖÇÁÀêÐÔøÌæÆÚ³¯¹××ØÌÄ¼¬ÔæÒÎ¶°¿ÃÉ­Õ»èþ°ôÆÜé¦Æå¹÷Ö²½·×µÃÞÅïèú¡õ¿îÆÛÇÕ²ÐÖ³¿ÇÌºµªÂÈë²¸ÛÓÎäÕ¶ÉäÖÓ¿´ÕÇþä×Ôü¼õÕ¿Ïæ²³ºþäÎÎ¼ÎÐÌÀ¿ÊÍÄÃì²âÅÈÓå»ë×Ì",
"¸È»ÁäÏ¡õäØ¡õ¡õäÒ±º·Ù½¹ÑæÎÞÈ»Öó¡õÅÆê÷Ï¬ÓÌâ«ºïÐÉ·©ç÷ÁÕ×ÁçúÅýÅÃÇÙ¡õè¡çùçûÉûËÕ»­·¬Á¡Í´ðë¾·¶»Æ¦¡õµÇ·¢Íîð©ñåµÁÀ§¶ÌÏõÓ²ÑâÉÔ¸Ñ³ÌË°Ï¡¾½´°½ÑÍ¯¿¢µÈ²ß±Ê¿ðÍ²´ðËñ½î·¤ÖþËÚÖà½Ê½áÈÞ¾ø×ÏÐõË¿Âç¸øÑ¤¡õç­ÉÆÏèôâñóñøËàÍóÇ»Ò¸¸­ÉöÕÍÌóÆ¢ëçëèëéÊæË´ÆÐÝÍÝÎÆ¼²¤ÝÑÝÂÝ¼»ªÁâ¡õ×ÅÀ³ÝÔÃÈ¾úÝÄ·Æ¾ÕÝÇÎ®ÌÑ²ËÜÉÝÊÝËÐéòÔÍÜòÎ»×Öë¸òòÐòÒ½Ö²ÃÁÑ¸¤ñûÊÓ×¢Ó½ÆÀ´ÊÖ¤Ú¬",
"Ú¯×çÕ©Ú®ËßÕïÚ­¡õÏóõõÖüÌù·¡êÝêÚ·ÑºØ¹óÂò±áÃ³´ûÔ½³¬³ÃõÉ¾à°ÏõÇÅÜµøõËõÌéðÖáéó¹¼´þåÓÖÜÒÝ½øåÔ¶õÓÊÏçÛ±º¨ËÖÁ¿³®Å¥¸ÆÄÆ¾û¶ÛîÔ¡õîÓãÉÈò¿ªÏÐ¼äÏÐãÈ¶Ó½×ËåÑôÓçÂ¡ÚòÚïµÌÑãÑÅÐÛ¼¯¹Íö©ÔÆÈÍÏîË³Ðëâ¸â¿·¹â½ÒûâÁ·ëÔ¦»ÆÊòºÚÂÒ¡õÕ®°Á´«½öÇã´ßÉËÉµÙÌ¡õ½Ë²ùØâÄ¼¡õÇÚÊÆ¼¨»ãàµàËÉ¤àÂÂðÊÈØÄà¾ËÃàÍàÅÎØÎËÐáÇºàÆà¼Ô°Ô²ÈûËÜÌÁÍ¿Ú£ËþÌîËú¡õ¿éÎëÛõÜã°Â¼Þ¼µÏÓæÅÂèæÁ",
"Ï±É©æÇáÔáÏ»Ï¸ÉÁ®ÏÃß±»ã¡õÎ¢ÓÞÒâ´È¸ÐÏë°®ÈÇ³îÓúÉ÷»ÅÀõã³âéâëÀ¢íªí©âýê¬ê«´ê¡õ¸ãÌÂ´î²ë°á²«ËÑÉ¦ËðÇÀÒ¡µ·¡õ¾´ÕåÐÂ°µêÍÏ¾ÔÎÅ¯êÑ¡õ¡õ»áÀÆÒµ³þ¿¬éªÐ¨¼«Ò¬¸ÅÑîèåé®Àã·ãéºÓÜé¬é¹¡õÐªËê»ÙµîØ¹ë¦ÒçËÝ×ÒÈÜäèÔ´¹µµáÃðäßäÛ¡õÄçÎÂ»¬×¼Áï²×ÌÏÏªäàäå¼åÑÌ·³ÃºÁ¶ÕÕìÏì¾ìã»Í»ÀÉ·¡õìÐ¡õÒ¯ëºéàÊ¨Ô³»«ÀÅº÷è¦ÉªÈðè£çõè§çøè¤µ±»ûðöÌµ´áÂéðò±Ôðô³Õ¡õÕµÃË¾¦½ÞÄÀíù¶½",
"¶ÃØº²ÇÕöî¢íþî¡°«ËéÅöÍëµâÂµµïÅð±®íÔ¡õì÷Â»½ûÍòÇÝ¡õÖÉ³íïþÙ÷ïý¿ßñ½¿ê½ÚóÞóßóÈÁ»¾¬ÔÁ¾­¾îÀ§°óËçÌÐÖÃÕÖ×ïÊðÒåÏÛÈºÊ¥Æ¸ËÁÒÞëìÑü³¦ÐÈÈù½ÅÖ×¸¹ÏÙÄÔ¾ËÍ§µÙ»çÂäÝæ¿ûÎ­ºùÒ¶Ôá¸ðÝàÝ«ÆÏ¶­ÝâÝçÝáÓÝÂ²ºÅÓ¼òÑòÚòØÊñ¶êÍÉ·äò×ò¹òÛÑÃôÄÒáÈ¹²¹ôÃ×°ÀïôÁÔ£Ùö¡õ½â²ï¸ÃÏêÊÔÊ«Úµ¿äÚ¶Òè³Ï»°Öï¹îÑ¯Ú¹Ú¸Õ²¡õö¤¡õ»¿õöºÑÔô×Ê¼Ö»ßêßÁÞÂ¸êà¼£¸ú¿çÂ·Ìø¶å¹òõÓ¡õ¶ã½ÏÔØéøéù",
"±ÙÅ©ÔËÓÎµÀËì´ï±ÆÎ¥åÚÓö¶ô¹ý±éåØÓâ¶Ý×Þ¡õ³êÀÒõ¤ÓÔîÜÇ¯îàîß¼ØÓËÇ¦ÅÙ¹³²¬ÁåîçîéîÒîëîäÃ­Õ¢°¯¸ôÔÉÓºöÁïô¡õÀ×µç±¢Áã¾¸Ñ¥°ÐÔ¤Íç¶Ùçï°äËÌËÇâÂ±¥ÊÎ³ÛÍÔÑ±÷Õð¯÷ä¶¦¹ÄÊóÉ®Ù×½ÄÙÒÙÔÁÅÆÍÏñÇÈ¹Í¡õ¡õ¾¤µÊ»®ØãØÑÑáàÕàÖÂï³¢ËÔÅ»Ì¾¼Îà¶¸Âà»ßõà½àÐ¡õßÙÍÅÍ¼³¾ÛÓ¾³Ä¹µæÇµÊû¡õÊÙâ·ÃÎâ¹¶áÞÆµÕæÏÄÛåýæÎæÐæÌ·õÄ¯Äþ¹ÑÁÈÊµÕ¯ÇÞå»²ì¶ÔÂÅÕ¸á«á¤±ÒÄ»àþá£ÀªÁÎ±×¡õÕÃ³¹¡õ",
"Ô¸Ì¬¿¶Âý¹ßâú²Ñ²Òã¼½ØÆ²ÕªË¤³·ÃþÂ§ß¡Þâ´ÝåºÞý²ôÇÃÎÓÆìì½³©ôßêÔ°ñÕ¥éÅéÂÈÙ¡õ¹¹é»È¶é½é¾Áñ»±Ç¹é¿é³¡õÅÌ¡õÇ¸¸èëµÕÄÑÝ¹öÀìµÎäöÑúÄ®×ÕÂ©Æ¯ººÂúÖÍÆáÊþ½¥ÕÇÁ°äîÂþäð³ºäô»¦ÓæÉøµÓÂ±ÈÛÎõÉ¿ÐÜÏ¨Ó«¶ûêûÜýÓüâ¯ÑþËöÂê¹åè©ÕçÒÉÅ±Ññ·è¡õ»¾¾¡¼àÃéî¥î£Ë¯´Åµú±ÌÌ¼Ë¶íÙìõ¸£»öÖÖ³ÆÍÝÎÑ½ß¶Ë¹Ü»þ¼ãóÛËãóé²­óÝóç¡õ¡õ´âôÕ¾«ÕÀçº×Û´Âç±ÂÌ½ô×ºÍø¸Ùç²³ñÃà²ÊÂÚÎ¬Ð÷ç»ç·",
"·£´äôäµÔÎÅ¾ÛÕØ¸¯°ò¸àëõ²²ÍÈëöê°Ì¨ÓëÌòÎèô»ÈØÝïÏ¯ÐîÃÉÝ°ÆÑËâ¸ÇÕôÝ¥Ýí¡õ²ÔËòÝîòêÃÛòßòìòáòæÖ©Ê´òéòèÉÑ¹ÓÅá¹üÂãÖÆñÔñÒ¡õËÐÖ¾ÓïÎÜÈÏ½ëÊÄÎóËµÚ¾»åÓÕÚ¿Ú½¡õºÀ¡õÃ²±öêâÉÞºÕÕÔ¸Ï¡õ¸¨éüÇáÍìÀ±Ô¶åÜÑ·Ç²Ò£µÝåÝ¡õåÞ±É¡õÛ´½ÍËá¿áõ©½ÂÒøÍ­Ãúîù¸õîýÏÎï§¡õÏ³ºÒ¹ëÃö¸ó·§¡õÏ¶ÕÏ¼Ê´ÆöÃÐè÷°÷±ÉØÆÄÁììªÌ¨½È±ý¶üâÃ²µ°¹÷»÷Ö¿ý»êÃùð°·ï÷á±ÇÆëÒÚÒÇÆ§½©¼ÛÙ¯¿ë¼ó¡õÁÝ",
"¾çÅüÁõ½£¹ôÛÄÀ÷ßëÎûàÚ³°ºÙ×ì»©ÐêÒ­àÛÅçË»Ð¥ß´Ü¯ÐæÔö·Ø×¹¶é¶Õ¡õ¡õæÒæµæ¿åü½¿æ¬å¼¿íÉóÐ´²ãÂÄáØ¡õ´±ÖÄá¦·Ï³øÃí¡õ¹ã³§µ¯Ó°µÂáçÇì»ÛÂÇí«Ä½ÓÇÆÝÎ¿ËËÓûã¿Á¯ÃõÔ÷ã½µ¬·ßã¾âäÂ¾Ä¦Ö¿Ä¡×²ÆËÀÌ³Å×«²¦ÄÓËºÁÃÈö´é²¥¸§ÄíÇËß¤¡õÞìµÐ·óÊýÄºÔÝ±©¡õÑùÕÁé¤×®Êà±ê²ÛÄ£Â¥·®½°ÀÖèÈéÊÁºÅ·Ì¾éäÒãÅ¹½¬äü³ÎÆÃÁÊ½à½½Ì¶Ç±äú³±ÅìäýÀ£Èó½§ÅËëøä±¡õ¡õÊì°¾ÈÈìÙë»¡õ½±â±Ó¨è°Á§",
"èªè­çÜñ¤´ñÎÁÁöÊÝ´¯ñ£°¨ÖåÅÌÏ¹ÃÐî§î¨¡õ´è°õÈ·ÀÚÄë¿ÄÂëÅÍ¸å¼Ú¹È»üð¢µ¾Ò¤Çî¼ýÏä·¶óð×­Æªóò¡õóóºýµÞÁ·Î³ÖÂ¼êÃå¼©±àÔµÏß¶Ð»ºç¶ç¼ç¿ç¾Âî°ÕôÉôæñîÌÅÄ¤Ï¥½º·ô±ìÕá±ÎÎµÁ«ÊßÒñÂûÃï½¯²Ì²·Åî´ÐÞ£¡õòëºûµûòðÏºÎÏ¡õòù»ÈòòòõÎÀ³åºÖ¸´°ýñÙ¡õñÛÒêÁÂÌ¸×»µ®ÇëÖî¿ÎÚÃÚÆµ÷Ë­ÂÛÚºÚÇ·ÌÚÄÍãÊúÖíÅâÉÍ¸³¼úÕË¶ÄÏÍÂô´ÍÖÊâÙô÷ÌËÈ¤¡õ¼ùõ×ÌßÌ¤²ÈõØ¡õ¾áÌÉ»ÔÁ¾ê¡±²éýÂÖê¢éþ",
"¹õÊÊÕÚåÛÔâÇ¨ÁÚÖ£µËÛ¶´¼×í´×ëçÐ¿ÌàÏúÆÌîí³úÂÁÈñï±·æ±µï®º¸ãÌÔÄÏööªÕðÃ¹¿¿°°Ð¬¹®ò¡¡õò¢¹ÎÑø¶öÄÙâÅÍÕ×¤æáÊ»æå¼Ý¾Ôæâ÷¼·¢÷×ÄÖ÷ÈÆÇöÏÂ³ð²Ñ»¡õôï÷âÀèÄ«³ÝÈå¾¡Ù±ÙÏÙ­¼½ÃÝÄý¼ÁØæÑ«àßàæµ±Ø¬àä¶ÖÔëÆ÷ßæàåàÈÊÉàÞ¸Á±Ú¿ÑÌ³ÛÕ·Ü¡õÙøÑ§å¾µ¼¡õÏÜÆ¾í¬±¹ãÁÒäº¶°ÃÐ¸Õ½ÉÃÓµµ²Ì¢º³¾ÝÂ°ÔñÀÞ²Ù¼ñÇÜµ£ÎÎÕûÀúÏþåßêÊê¼¡õé×¡õèë³ÈºáéÙÊ÷éÏÍÖÏðÇÅÇÁéÔ»úèãì¨Àúë©å¥µíÔè",
"Å¨Ôó×Çå¢°Ä¼¤å£å¤¡õäÅ¡õ³ãìÀ¡õÉÕµÆÑàìäÁÇÌÌìËÈ¼¡õ¶Àè«çá¡õ¡õè±Æ°ê±ÝùÕÎÈ³¡õÂ¬îÂîªÂ÷î©Æ³Ä¥×©íàíÓÓù»ýÓ±ÄÂöÕ¡õ¿ú¸Ý¡õ¡õóÆ¡õ´ÛÉ¸ó÷¸âÌÇçËçÌÝÓ¸¿ÏØçÉçÇçÆç§î¾ôËº²°¿ôçññÉÅÄåÅòÕéÐËËÒ²ÕÈïÞ¥Þ¦Þ§µ´Þ¬½¶ÏôÎßÞ©ó¦ÃøÂìÓ©ÈÚºâÍÊ¿ãÈìñÝñ×Ç×êìÚÐÑèÚÉ»äÄ±µýÐ³ÚÑÅµÚËÎ½·íÚÍÚÏÚÈÚÎÔ¥¡õÃ¨ÀµÌãõâÓ»õå¡õõà·ø¼­Êäê£±æ°ì×ñåàÑ¡³ÙÁÉÒÅÚþÐÑ¶§±í¾âÃÌ´íÇ®¸ÖÎýÂ¼ï£",
"×¶½õ¡õï¿ïÀïÅÑÖËíËæÏÕµñö®Õ´ÁØ»ôÄÞö­µå¾²¡õÇÊ¼Õ¾±Æµò¥Í·ÍÇÒÃ²Í¹Ý½¤âÆÏÚëÈº§æéÂæº¡÷À÷Ù÷Úºå±«ÍÒð³ÑìÑ¼¡õÔ§Ä¬Ç­Áú¹êÓÅ³¥ÀÜ´¢Àøº¿ßÌ¡õàéÏÅÌçº¾Ñ¹ÛÖ¡õÓ¤æÉæÖÈæÞÏåðÓìÁëÔÀáÉ°ïÃÖ»ÕÓ¦¶®¿ÒÅ³í®Ï·´÷Çæ»÷ë¢¼·Å¡²ÁÄâ¸éßª¡õÁ²±ÐÊïêÓÌ´µµÏ­¼ìèíèÎéÉ¡õéÞéÜéÑ¡õéç¡õÕ±Å¢±õ¼Ãå©ÃÉÌÎÀÄåªÉ¬¡õå¦¡õÊªå§Î«ìÝÓªÛÆ²ÓÔïÖò»Ù»âìÛ¾ôÇ½Äü»ñè³»·è¨è²ðìÁÆ°©ÌÀÍ«µÉî«Ë²",
"ÇÆÁË½ÃÁ×»Çíãí¶½¸ìûìøËëÁþ´ØÂ¨óúÅñóù¡õ¿·ÃÓ·à¡õÔã²ÚôÖËõ¼¨çÑÂÆçÐ±Á·ì×Ü×ÝçÒ·±ÏËçÎ¡õçÏ¡õ¡õóÀôèÒíñúÉù´ÏÁªËÊÒÜÓ·âß±ÛÍÎÅ§µ¨Á³ëÚÁÙ¾Ù¼èÐ½±¡ÀÙÞµ½ªÇ¾ÊíÑ¦Þ±Þ°¼»¿÷ó°ó¯ó«òþó¡ó§ò÷ÂÝòåó¬ÙôñÞÏåñÚ¡õêéÃÕ°ùÇ«½²»ÑÒ¥Ð»ÌÜÚ×»íÏªáÙ×¬Èü¹º¡õêçÇ÷õãÌ£µ¸õèÏ½Õ·ì±Ô¯Óß±Üåá»¹ÂõåâÑûÛ¸õ±ÔÍ³ó¶ÆÃ¾Ãª¼ü¡õïÆ¹ø´¸ïñÇÂ¶ÍïÌ¡õïÉÀ«ã×À»ãÇ°åÒþÁ¥ËäËªÏ¼¾Ïº«¿Åì«¡õ³Ò",
"¿¥ÏÊöÞöÛ¡õºè¸ë÷çð¤µã÷í÷î÷ì÷ýÕ«´ÔààÏòÛÛÀÝÉôÒÍí¯´ÁÀ©ÖÀÈÅÄì°ÚËÓß¢¶Ïê×ëüéÄÃÊ¹ñ¼÷Äû¡õ¡õÌ¨ì£¹ééëÐºäÉÂËäÂ½¦ÆÙä¯Ñ¬½ýìâ¡õáîÁÔèµ¡õ¡õñ±ðÝÓúî­öÄÕ°íú´¡Àñð£»à¡õ´ÜÇÏóï»Éô¢óìóñ¼òÁ¸Ö¯ÉÉÈÆçÔÐåçÕ¡õ¡õÇÌ·­Ö°ÄôÆêë÷¾É²ØÈøÀ¶Ãê½åÞ¹ÜùÞ·¼öòÍ²õ³æó´¸²êîõüÚÓ½÷ÃýÚØ·á×¸õ¾õç±Ä×Ù¼£õÏÇû×ªÕÞåÇåäåãÒ½½´¡õ¡õ°÷ËøÎÙÄøÕò¸äï×ïÓ¡õ¡õãØ´³ãÙãÚÀëÔÓË«³û¼¦¡õ÷·Çï",
"±Þ¡õ¶îÑÕÌâò¦ò§¡õÁóâÈ¡õ÷Ñð¥Æï÷Á××ËÉÎº÷Ë÷ÍöèÀðöê¡õöç¾é¶ìðÀ÷ï¡õ÷ø¡õ¡õ»µÂ¢ÛÞ³èÅÓÂ®³Í»³ÀÁãÂÅÊÂ£¿õÆØ³÷èüéµéÖå­äìäþå«Á¤±ôãò±¬Ë¸ë¹¶¿ÊÞÌ¡çôÇí°ê³ë½®±ñ³ÕÃÉ°­µ»»ñÎÈ¡õ²¾ô¤Ç©éÜô¦Ïµ¼ëÒïÉþ»æÂÞ½É¡õ¸þÙúÀ°·ªÒÕÞ´ÅºÌÙÒ©¡õÒÏÓ¬Ð«Ð·ó¸ñÉ½ó°ÀôÅ»©Æ×Ê¶Ö¤Ì·ÚÜ¼¥¡õÚÛÔùÔÞõë¶×³ùõêµÅõÎõíê¥½Î´Ç±ßåå¡õõ´¾µïá²ùïßÁ´ïÛïÜ÷éïÚïÝïÏïÎï¬öÉ¹ØÂ¤ÄÑö¯ÎíÃÒèºÔÏÀà",
"Ô¸µßì¬ÂøâËæðÆ­ºú¾¨öðöëöôðÈðÄÈµðÆÅô÷èÀöÂ´ôðÈ°ÁüÈÂàÓÑÏ½ÀÈÀæ×ÄïÄõ±¦¡õÐüâãÈÁÀ¹²óêØëÊé´À½ÃÖäòÂ¯Ï×ççÑ÷¡õ¿óíÂ·¯Àùñ¼¾º³ïÀº¼®Å´ÍÅ±èçÍ¼Ì×ëó¿Ò«ëÍ½¢Ôå°ªÄ¢ÝþÂ«Æ»ËÕÔÌ¡õÈäñÜ¾õ´¥ÒéÆ©¾¯ÒëÔëÚÞÓ®ÉÄõ»Ôêõî¡õõ·ÊÍÖÓîóÐâ²ûö±Æ®ÈÄ¡õÜ°å¹ÌÚÉ§¡õÈúöúÏÌÃæµ³÷ùö´³öÁäÙ³¡õà¿ßùÏùÙçÊôÎ¡¾åÉåÉãÐ¯ìµêÙÓ£À¸èù¼ß¹àÀÃÎþ¡õè¬ñ®ëÊ¡õ²øÐøåñ¡õÀ¼ÞºòÃ´Àó»À¯Íà¡õÀÀÇ´",
"»¤ÓþÔß³ìÔ¾õÒºä±çõ¸Á­ÀØÌúîõîìïíïÔ±Ù°ÔÅùÂ¶Ïì¹Ëò«÷ÏÇýæôÝëÂâ÷ÃÄ§÷Î÷¢÷¤Ýºº×ðÎ¡õ÷ê÷öÜ±ö·ö¸¡õÙ²ÙÎß½ÄÒÂÞÂÏáÛÂÍÍäÜ²Ì¯È¨»¶¡õÌ²â¤È¿µþñ«Ñ¢ìüÁýô¥ÁûÌýÔàÏ®³Ä¡õ¶ÁÊêØÍõÜõÙàÎÛªÖý¼ø¼øö«ö²÷²¡õ²ü÷Ò½¾æçÔàÐë±îöã÷§÷©ðÑÅ¸÷úö¹öº¹¨ËÕ¡õÁµÂÎ¾ð½ÁÉ¹¡õè¶ÇÔÇ©¡õ¡õÓ§ÏË¡õ¡õÕºÂÜ¹Æ±äåÎÂßïðîå¡õØÌÏÔ÷Ð¾ªæäÑéËèÌå÷Ç÷­ÁÛ÷¬ð¸÷ë¡õÖö°ÓÀ¿å±Ì±ñ²´£¹Þî¿²Ïó¼áéÈÃ²÷",
"ÚßÑÞ¸ÓÄð¡õö¨Áéö°Ç§ò­Öè÷Þ÷Êö×Ó¥ðØ¼ïÑÎ¡õö»È£Ìüé­ÍåÀéÂáÂù¹Ûõæ¡õÏâÔ¿Â­²ö÷Å÷àÙäÂÐÖõÔÞÄ÷÷µÂ¿æ÷ÀÂÚÔõïõ¦×êöÇÂàöùöÔ÷ò¡õÔäðÐìàæêÓôðÙð½Óõ¢Ù¢Ú¢Û¢Ü¢Ý¢Þ¢ß¢à¢á¢â¢Å¢Æ¢Ç¢È¢É¢Ê¢Ë¢Ì¢Í¢Î¢ñ¢ò¢ó¢ô¢õ¢ö¢÷¢ø¢ù¢ú¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õØ¿¡õØÎ¡õÍòØ¢Ø±Ø¡¡õ¡õ¡õáÜ¡õ¡õ¡õ¡õØÁØìØë¡õ¡õ¡õ°º¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØí¡õ¡õØîÙÚ¡õ¡õ¡õ¡õ¡õ¡õ¡õº»¡õå³¡õåê¡õ¡õ¡õâÏ¡õâá¡õ¡õë­¡õ¡õ¡õ¡õ¡õáì¡õ¡õ¡õ¡õ¼¿¡õ¡õØõ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØó¡õ¡õ¡õ¡õÙü¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õàïØ¶ÛÜ¡õ¡õÞÅ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæØÞÍ¡õá¨¡õ¡õ¡õ¡õ×¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÇ¤¡õ¡õ¡õ¡õ¡õê¹ê¸¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õë®ÙÛ¡õãá¡õãâãà¡õ",
"¡õ¡õ¡õáí¡õçà¡õ¡õ¡õ¡õ¡õ¡õ¡õÜ´Üµ¡õ¡õÚøÚõ¡õÚö¡õÚã¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØô¡õØû¡õÙ¡¡õÙÜ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛ¿¡õ¡õØÕ¡õ¡õ¡õ¡õ¡õ¡õß¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛÐ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæ¡¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õá©¡õá¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâÑ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õß¯ìýìþâí¡õâå¡õâçâè¡õ¡õ¡õÐÚÐÃ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¿¼êº¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õè»è¾¡õ¡õ¡õ¡õ¡õë¯ë°¡õ¡õ¡õ¡õ¡õÆã¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáð¡õáñ¡õ¡õ¡õ¡õ¡õ¡õ¡õî®¡õðÛ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õëÀ¡õÜ¶¡õÜºÜ»¡õÜ·¡õÜ¹õô¡õ¡õ¡õÚú¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙ®¡õ¡õ¡õ¡õÙ¥Ù¦Ù¨Ö¶¡õ¡õ¶±¡õáß¡õ¡õ¡õ¡õ¡õÙ°¡õ¡õ¡õ¡õ¡õ¡õ¡õÙþ¡õ¡õ¡õØÚ¡õ¡õ¡õ¡õÌÕ¡õ¡õ¡õ¡õ¡õ¡õ¡õßÆ¡õ¡õ¡õ¡õ¡õ¡õ¡õßÏ¡õ¡õ¡õ¡õ¡õ¡õ¡õßÊ¡õàòÅ÷¡õÛèÛã¡õ¡õÛé¡õÇðÛæÛê¡õ¡õ",
"Ûç¡õ¡õ¡õ¡õ¡õ¡õ¡õæ§¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæßæÛåµå´¡õ¡õ¡õ¡õ¡õá²¡õ¡õáµ¡õá¸¡õá³¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õàúàù¡õ¡õ¡õ¡õ¡õáÞ¡õ¡õ¡õ¡õ¡õâñâï¡õ¡õ¡õâ÷¡õ¡õ¡õ¡õ¡õ¡õâô¡õ¡õ¡õ¡õ¡õ¡õ¡õê§ìæ¡õ¡õ¡õ¡õ¡õ¡õÞÔ¡õ¡õ¡õÞÓ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õê¾¡õ¡õ¡õ¡õ¡õ¡õ¡õëÃ¡õ¡õ¡õ¡õ¡õ¡õèÄ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õí³¡õãùãú¡õ¡õãïãð¡õ¡õãî¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÈ²¡õêÁ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáô¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õçã¡õ¡õ¡õ¡õ¡õ¡õî¯çÞ¡õ¡õ¡õ¡õíì¡õ¡õí·¡õ¡õ¡õ¡õ¡õËû¡õ¡õñ¶¡õ¡õ¡õ¡õñô¡õ¡õ¡õ¡õ¡õëÇ¡õ¡õ¡õÜ¾¡õÜÅ¡õ¡õ¡õÜÇ¡õ¡õ¡õÜÌÜ¸ÜÍÜË¡õÜÒ¡õ¡õ¡õ¡õò°¡õ¡õ¡õ¡õ¡õåÂ¡õ¡õåÃ¡õ¡õÚûºªÚüÛ¢¡õÚçÚè¡õ¡õ¡õÙ´¡õ¡õ¡õ¡õÙ¶¡õÙ·¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØÙï±¡õ¡õ¡õ¡õ¡õ¡õØÇÀå¡õ¡õßÒ¡õßç",
"¡õ¡õßû¡õ¡õ¡õ¡õ¶ß¡õ¡õ¡õ¡õ¡õßÚßè¡õ¡õ¡õ¡õÛìÛí¡õ¡õ¶â¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæ­¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õá¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÚá¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâÓ¡õ¡õåè¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâþÐÚ¡õ¡õ¡õ¡õ¡õ¡õìç¡õ¡õ¡õ¡õ¿æ¡õ¡õ¡õ¡õ¡õ¡õÞÙ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêÆ¡õ¡õêÇ¡õ¡õ¡õ¡õ¡õ¡õêÃêÄ¡õ¡õ¡õëÔèÞ¡õ¡õ¡õ",
"¹ñ¡õ¡õèÏ¡õ¼Ï¡õ¡õ¡õ¡õèÕ¡õè×¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õèÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õèÚ¡õ¡õ¡õéãéå¡õ±Ñ¡õ¡õ¡õë±¡õ¡õ¡õ¡õ¡õ¡õÈ÷¡õ¡õä²ä§ä¨¡õä®¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õä¦¡õ¡õ¡õ¡õ¡õ¡õìÄ¡õ¡õìÆ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêð¡õ¡õáõ¡õ¡õ¡õ¡õ¡õ¡õ¡õçæçì¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÎÍ¡õ¡õî²¡õ¡õ¡õ¡õíñ¡õíí¡õ¡õ¡õ¡õ¡õïò¡õ¡õí¼Åø¡õ¡õ¡õ¡õí¹¡õ¡õ¡õ¡õ¡õ¡õ¡õïõ¡õ¡õ¡õ¡õñ¸",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæý¡õî·¡õ¡õ¡õ¡õ¡õ¡õñèÞÇ¡õÛÏ¡õ¡õ¡õëÏ¡õ¡õ¡õëÑ¡õ¡õ¡õ¡õ¡õëÓ¡õëÒ¡õô­¡õ¡õ¡õ¡õÜØ¡õ¡õÜæÜûÉ»¡õÜÚ¡õÜÓ¡õ¡õÜÝÜÞ¡õ¡õ¡õÜÖÜå¡õ¡õ¡õ¡õ¡õò´¡õ¡õ¡õ¡õ¡õñÃ¡õ¡õÙê¡õ¡õ¡õåÅ¡õ¡õ¡õ¡õ¡õÛ¤Û¥Û¨¡õ¡õîÆîÅÚë¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ±í¡õ¡õ¡õÙ¾¡õ¡õ¡õÙÃ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØß¡õ¡õØÞ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õßêßî¡õ¡õÛÁßÂ¡õ¡õßò¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛôÛø¡õ¡õ¡õ¡õÛù¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØ«¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õåò¡õ¡õí¢í£í¤í¥¡õ¡õ¡õã¨¡õã¦ã§¡õãª¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÍ±¡õÞÜ¡õÞÚÞÛ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì·ì¹ì¸¡õ¡õêÉ¡õ¡õ¡õ¡õ¡õ¡õèñèàèá¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õèäèæ¡õèé¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õä½¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õä´ä³¡õ¡õ¡õ¡õä·¡õä»¡õ¡õä¼¡õÍ¿¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáþáù¡õ¡õáüâ¡áû¡õçîçí¡õ¡õçò¡õçñ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õð¬¡õê²¡õ¡õî³¡õðæ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíôíòíó¡õíÈíÇ¡õ¡õ¡õ¡õ¡õ¡õ¡õíÉ¡õ¡õ¡õ¡õìî¡õìïìð¡õ¡õïø¡õ¡õ¡õïö¡õ¡õ¡õ¡õñ¹¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"óÇ¡õ¡õóËóÅóÉ¡õ¡õ¡õ¡õôÎ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õç£¡õ¡õ¡õ¡õ¡õî¸¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñé¡õ¡õ°·¡õ¡õ¡õ¡õ¡õ¡õô¨ô±¡õÜüÜú¡õ¡õÜè¡õ¡õ¡õ¡õ¡õÜç¡õ¡õ¡õÝ¢¡õÜëÜí¡õ¡õ¡õ¡õ¡õÜò¡õÜô¡õ¡õ¡õ¡õ²ç¡õ¡õ¡õ¡õ¡õ¡õò¶¡õò·¡õ¡õ¡õ¡õ¡õò¸¡õ¡õ¡õ¡õ¡õò»¡õ¡õ¡õòº¡õ¡õ±­ô¬¡õ¡õ¡õñÄ¡õ¡õñÆ¡õ¡õôÀ¡õ¡õ¡õôø¡õ¡õ¡õ¡õ¡õ¡õõÀ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õåÌ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛ£¡õ¡õÛ®Û­Û¬¡õôû",
"ôüôýîÉ¡õ¡õ¡õÚìöÀ¡õ÷ÔÛË¡õ¡õ±Æ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¹ÐÛÃ¡õØÐ¡õà£à¤¡õ¡õßý¡õßô¡õ¡õ¡õ¡õà§¡õ¡õ¡õ¡õÉ¶¡õ¡õ¡õ¡õ¡õ¡õ¡õàõàð¡õ¡õ¡õ¡õ¡õÛúÜ¥Ü¤Ü£¡õÛüÜ¡¡õÛïÝÀ¡õ¡õ¡õ¡õ¡õÛë¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÜ¢¡õ¡õ¡õ¡õæ¼æº¡õ¡õ¡õæ«¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õåíáÆ¡õ¡õ¡õ¡õ¡õ¡õáÁáÃ¡õ¡õ",
"¡õ¡õ¡õ¡õáÄ¡õ¡õ¡õ¡õâÕ¡õâØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õã®¡õã­¡õ¡õ¡õ¡õ¡õ¡õ¡õêý¡õÞåµà¡õ¡õ¡õÞÝ¡õ¡õ¡õÞá¡õ¶ÞÆþ¡õ¡õ¡õ¡õÞãÞç¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêÎ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õèõ¡õèôèö¡õ¡õèø¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì¤¡õ¡õ¡õéè¡õ¡õë´¡õäÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õäµ¡õ¡õ¡õäÄ¡õÄ×¡õäË¡õäÇ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÍé¡õÌþ¡õ¡õ¡õ¡õìÉ¡õ¡õ¡õìÊ¡õ¡õ¡õ¡õ¡õ¡õêõ¡õ¡õêöâ§â¢¡õ¡õ¡õâ¥¡õ¡õ¡õâ¦¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÑ÷¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíõ¡õ¡õ¡õ¡õ¡õ¡õ¡õí÷¡õÎø¡õ¡õ¡õíÑíÎ¹èíÏ¡õìö¡õ¡õ¡õ¡õ¡õ¡õ¡õ½Õ¡õ¡õ¡õ¡õ¡õ¡õóÌ¡õóÓ¡õ¡õóÔóÕ¡õóÎ¡õóÑóÊ¡õ¡õ¡õóÍ¡õ¡õ¡õÕ³¡õ¡õ¡õ¡õ¡õ¡õç¤¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õôÆ¡õñ´¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õñõ¡õëä¡õ¡õëÖ¡õ¡õëãëâ¡õ¡õ¡õ¡õ¡õ¡õô´ô¶¡õô·¡õåõ¡õ¡õÝ¹¡õ¡õ¶¹¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÝ³Ý´¡õ¡õ¡õÜðÝ­¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòÅòÄ¡õ¡õ¡õ¡õ¡õòÊ¡õ¡õ¡õ¡õ¡õìÅ¡õ¡õ¡õñÈ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙó¡õ¡õ¡õ¡õ¡õõû¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõÂ¡õ¡õõÁ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õåÍåÏ¡õ¡õåÒÛ°¡õ¡õ³»¡õ¡õ¡õÛ¯¡õ¡õ¡õ¡õ·Ó¡õ¡õ¡õ¡õ¡õ¡õ¡õîÌîÏ¡õ",
"¡õîÊ¡õ¡õ¡õãÆ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØ¸¡õ¡õ¡õ¡õ¡õ´ö¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õà³¡õ¡õ¡õ¡õ¡õ¡õ¡õà®ßöß÷à¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÜ§Ü¦¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæ£¡õ¡õæÄ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáÑ¡õáÒ¡õ¡õ¡õ¡õ¡õáÎ¡õ¡õáÌ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õá¢¡õåé¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"ã¢¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêþÞï¡õ¡õ¡õ¡õ¡õ¡õ¡õÞëÞÞ¡õÞé¡õ¡õ¡õÞò¡õ¡õÞí¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ±ó¡õ¡õ¡õ¡õì¼¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÀâèâèÇ¡õ¡õ¡õ¡õ¡õé§¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õèû¡õé£¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì¥¡õ¡õ¡õ¡õ¡õ¡õ¡õëÈ¡õ¡õë¥Çèíµ¡õ¡õ¡õ¡õãí¡õ¡õ¡õ¡õäÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õä¥",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õäÐ¡õ¡õ¡õäÔ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õìÌ¡õ¡õìÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêø¡õ¡õ¡õâ©â®¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õçýçþçü¡õ¡õè¢¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õå¸¡õî´ðð¡õ¡õðí¡õ¡õðî¡õ¡õ¡õ¡õ¡õíû¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õïó¡õíÌ¡õ¡õíË¡õ¡õ¡õ¡õ¡õíº¡õ¡õ¡õ¡õ¡õ¡õïü¡õïû¡õ¡õ¡õñµ¡õ¡õ¡õ¡õ¡õóÜ¡õ¡õóØóÚôÒôÑ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õç¬¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õôª¡õ¡õ¡õ¡õ¡õºÊÝÏ¡õÝÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÝ½ÝÃÝ¾Ý¿¡õÝÕ¡õ¡õÝÅ¡õ¡õ¡õÝÌ¡õÝÈÝÉ¡õ¡õ¡õ¡õ¹½¡õÝÐ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòÕ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòË¡õ¡õòÖ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñËñÊ¡õ¡õ¡õñÌ¡õêè¡õ¡õõý¡õÚª¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÚ±îº¡õ¡õ¡õ¡õ¡õ¡õ¡õêÜ¡õêÛ¡õ¡õôò¡õ¡õ¡õ¡õ¡õ¡õõÅ¡õõÊ¡õ¡õ¡õõÆ¡õ¡õ¡õé÷",
"éò¡õ¡õ¡õ¡õ¡õ¡õ¡õéô¡õ¡õ¡õ¡õåÕ¡õåÖÛ©¡õÛ²¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõ¢ôþ¡õõ¡¡õîÕ¡õîØ¡õ¡õîÑ¡õ¡õîÙ¡õ¡õ¡õ¡õî×îÖ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãÊ¡õ¡õ¡õÚñÚí¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñü¡õâÀ¡õíé¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÏÉØñ¡õÙÍ¡õ¡õÙÑ¡õ¡õÙÝ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õàÉ¡õ¡õ¡õàÃ¡õàÁàÄßï¡õàª¡õ¡õ¡õ¡õà²¡õàÇàÊ¡õ¡õ¡õ¡õ¡õÛ÷Ûîëó¡õ¡õ¡õ¡õ¡õ¡õÜª¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæÊ¡õëô¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáÓ¡õ¡õáÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì°¡õáæ¡õ¡õã»ãº¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õê­ê®¡õ¡õ¡õ´¤¡õ¡õÞ÷¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞù¡õ¡õÞô¡õÌÍ¡õ¡õÎæ¡õ¡õÞõ¡õÞö¡õÞú¡õ¡õ¡õ¡õ¡õêÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õé¸¡õ¡õ¡õ¡õé¨´»¡õ¡õé©é«é¥¡õ¡õ¡õ¡õ¡õ¡õ¡õ´ª¡õé¢é±é²¡õ¡õ¡õØÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì§¡õì¦¡õ¡õ¡õéê¡õ¡õ¡õ",
"ë¨¡õ¡õ¡õ¡õ¡õäç¡õäé¡õ¡õ¡õäÚ¡õ¡õ¡õäá³ü¡õ¡õäã¡õ¡õ¡õäæäÑ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì¿¡õ¡õ¡õ¡õÜäìÒìÔ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêù¡õ¡õ¡õ¡õ¡õ¡õáø¡õ¡õ¡õ¡õ¡õ¡õçâ¡õ¡õè¥¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õê³¡õ¡õ¡õîµ¡õ¡õ¡õ¡õðñ¡õ¡õðó¡õ¡õðõ¡õ¡õ¡õ¡õ¡õðª¡õ¡õ¡õ¡õ¡õ¡õ¡õíý¡õ¡õ¡õ¡õ¡õ¡õíÖíÕ¡õ¡õ¡õ¡õ¡õ¡õíØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ°Þ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õóâ¡õ¡õóã¡õ¡õ¡õ¡õ¡õôÓ¡õ¡õç°ç®¡õ¡õ¡õ¡õ¡õ¡õ¡õç¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õî»¡õ¡õôÇôÈ¡õ¡õ¡õ¡õëí¡õ¡õëî¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õëá¡õôºô¹¡õ¡õ¡õ¡õ¡õ¡õÝã¡õ¡õ¡õ¡õÝ×¡õ¡õ¡õ¡õ¡õ¡õÝØÝÙ¡õÝÚ¡õ¡õ¡õ¡õ¡õ¡õÝÝ¡õÝß¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ±â¡õ¡õÝ¦¡õ¡õÝå¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòÌ¡õ¡õ¡õòÙ¡õòÝ¡õ¡õòÜ¡õ¡õ¡õ¡õñÎ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õö¡¡õ",
"¡õ¡õ¡õõþ¡õ¡õÚ²Ú´Ú¼¡õ¡õ¡õÚ³Ú·¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõ÷¡õ¡õ¡õôô¡õ¡õ¡õ¡õ¡õôó¡õ¡õ¡õ¡õõÍ¡õ¡õ¡õ¡õõÐ¡õ¡õ¡õõ¼¡õ¡õ¡õ¡õ¡õéûéú¡õ¡õ¡õåÙ¡õå×¡õ¡õ¡õ¡õ¡õ¡õÔÇÚù¡õ¡õÍªõ¥îè¡õîæîÚîÛîÝ¡õîáï¥îê¡õ¡õîãîâ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÚóöÂ¡õ¡õ¡õ¡õ½ù¡õ¡õ¡õñþ¡õñý¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙì¡õö¼ÙÖ¡õ¡õÙÇËÛ¡õ¡õ¡õ¡õ¡õÙÕ¡õ¡õ¡õ¡õ",
"¡õ¡õØä¡õ¡õ¡õ¡õà×¡õàÑ¡õ¡õØÅßéàÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õÜ­¡õ¡õ¡õ¡õÜ¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæÑ¡õ¡õ¡õ¡õ¡õ¡õæÆ¡õ¡õæË¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õåïáÖ¡õ¡õ¡õ¡õáÐ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õàý¡õ¡õ¡õâÛ¡õ¡õ¡õ¡õ¡õâÚ¡õ¡õ¡õ¡õ¡õ¡õí¨¡õ¡õ¡õã¥¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâæ¡õ¡õê¯ê¨¡õ¡õ¡õ¡õ¡õ¡õÞÒ¡õ¿Ù¡õ¡õ¡õ¡õ¡õÁÌÞûÞè¡õ¡õ¡õ¡õ¡õë¡¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéÁ¡õ¡õ",
"¡õé¶¡õ¡õ¡õ¡õ¡õ¡õ¡õé¼éÇ¡õ¡õ¡õèç¡õ¡õ¡õéÀ¡õéÃ¡õ¡õ¡õ¡õè¿¡õ¡õ¡õ¡õÞø¡õ¡õ¡õ¡õ¡õ¡õ¡õéæ¡õ¡õ¡õ¡õ¡õÜþ¡õ¡õ¡õ¡õä°¡õ¡õ¡õäõ¡õ¡õÅ½¡õ¡õ¡õ¡õ¡õ¡õäñ¡õäï¡õäÝ¡õ¡õ¡õäÓ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÑ¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ´ôâ°¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õðøðý¡õðú¡õñä¡õ¡õ³ò¡õ¡õî¦¡õ¡õ¡õíÚ¡õ²êí¸¡õ¡õ¡õ¡õíÜ¡õ¡õ¡õ¡õ¡õìù¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ±â¡õñ¿¡õñ¾¡õ¡õóí¡õ¡õóä¡õ¹¿¡õ¡õ¡õóë¡õÔý¡õ¡õ¡õ¡õ¡õôÔ¡õ¡õ¡õ¡õç¹¡õ¡õ¡õ¡õ¡õ¡õçµ¡õç³¡õ¡õç¸¡õ¡õ¡õôëôì¡õ¡õ¡õ¡õ¡õ¡õôã¡õ¡õ¡õ¡õ¡õà¼ëð¡õ¡õ¡õ¡õ¡õÝõ¡õÝò¡õÝð¡õ¡õ¡õ¡õ¡õÝóÝôÝèÝé¡õ¡õ¡õÝê¡õ¡õ¡õ¡õÝª¡õ¡õ¡õ¡õØá¡õ±Í¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòÞ¡õ¡õ¡õòâòà¡õ¡õ¡õ¡õ¡õ¡õòä¡õ¡õ¡õ¡õ¡õ¡õÑÑ¡õòç¡õ¡õ¡õ¡õ¡õ¡õòã¡õ¡õ¡õ¡õñÑ¡õ¡õñÕ¡õñÓ¡õ¡õ",
"ñÖ¡õ¡õ¡õêê¡õ¡õ¡õö¢¡õ¡õ¡õ¡õÚÀ¡õ¡õ¡õ¡õ¡õêä¡õ¡õ¡õõÔ¡õ¡õ¡õõÕÓ»¡õ¡õ¡õõ½¡õ¡õ¡õ¡õ¡õ¡õ¡õÛµ¡õ¡õÛ³¡õ¡õ¡õ¡õ¡õ¡õ¡õõ¨õª¡õÒ¿¡õ¡õ¡õîïîî¡õîð¡õî÷ï¢ï¤¡õ¡õîþï¨îñöÆ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õîû¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì©¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷º¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙÓÙØ¡õ¡õÙÙ¡õ¡õ¡õ¡õØÛÛ½¡õ¡õ¡õàáßØ¶ñ¡õ¡õ¡õàÙ",
"¡õ¡õ¡õ¡õàÜ¡õß¼¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õá×áÀ¡õ¡õ¡õ¡õ¡õá½¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâÜ¡õâÐ¡õ¡õ±ï¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õã´¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞþ¡õ¾ï¡õ¡õ¡õ¡õ¡õ¡õµ§ÞØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéË¡õ¡õ¡õ¡õÁ¬¡õéÈ¡õ¡õ¡õ¡õ¡õ¡õéÎ¡õ¡õ¡õèý¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéÌ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õë§¡õ¡õ¡õ¡õÀÔ¡õ¡õ",
"äøä÷äùäê¡õ¡õ¡õ¡õ¡õ¡õ³Î¡õäû¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õä¶¡õ¡õää¡õ¡õ¡õ¡õ¡õ¡õìÚ¡õ¡õìØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì×¡õ¡õ¡õ¡õ¡õ¡õâ²¡õ¡õ¡õ¡õ¡õ¡õè¯çö¡õ¡õè®¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õðûðùðþ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õî¤¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíÝ¡õ¡õ¡õíßìú¡õ¡õ¡õ¡õ¡õ¡õð¡¡õ¡õñÁ¡õóæ¡õóè¡õ¡õ¡õ¡õ¡õôÛôÚôØ¡õ¡õ¡õ¡õ¡õç½çÅ¡õ¡õçÁçÂçÃ¡õ¡õ¡õ¡õ¡õôÊ¡õ¡õ¡õ¡õ¡õôå¡õ¡õ¡õëù¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õô¼¡õ¡õ¡õ¡õ¡õ¡õÞ¢¡õ¡õ¡õ¡õ¡õ¡õÝý¡õ¡õ¡õ¡õÄè¡õ¡õÝø¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ¤¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÜêÝä¡õ¡õÜà¡õ¡õÝûÜÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õë½¡õòöòø¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õòó¡õòú¡õòï¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÚÁ¡õ¡õ¡õÚÂ¡õ¡õ¡õÚÅ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÖÜ¡õêã¡õêæ¡õ¡õ¡õ¡õ¡õõÛ¡õ¡õõÚ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"õÖ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛ·¡õ¡õ¡õµ¦¡õ¡õõ¬Õµ¡õ¡õ¡õ¡õ¡õ¡õï¶¡õ¡õ¡õ¡õîòï«ï·¡õ¡õ¡õï²îúï¯¡õï°¡õöÈ¡õï¸¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãÏãÍ¡õ¡õ¡õ¡õ¡õ¡õö¬¡õö¦¡õ¡õ¡õ¡õ¡õ¡õ¡õò¤¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâÄ²¸¡õ¡õ¡õ¡õ¡õ¡õ¡õæà¡õ¡õ¡õææ¡õ¡õ¡õ¡õ¡õ÷Ø¡õ¡õ¡õ¡õ÷É¡õöÐ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õð±¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØ¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õßÕ¡õ",
"¡õßÜ¡õ¡õßà¡õ¡õà÷¡õ¡õ¡õ¡õ¡õ¡õ¡õÛÔ¡õæÓæÍ¡õæÈ¡õ¡õ¡õæÔ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õá»¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâÞ¡õ¡õâÝ¡õ¡õáèí­º©¡õ¡õ¡õ¡õ¡õâø¡õ¡õ¡õ¡õß¨¡õß§¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêÕ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéÐ¡õ¡õ¡õéÓ¡õéØ¡õ¡õ¡õ¡õ¡õ¡õéÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéìéé¡õ¡õ¡õ¡õë«¡õ¡õ¡õ¡õ¡õ¡õ¡õÂº¡õ¡õ¡õ¡õ¡õ¡õ¡õä«¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õå¡¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õìÇ¡õìÜ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâ³¡õáýáö¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñ¦¡õ¡õñ¬ñ¢ñ©¡õñ§¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ«¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õí×¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñÀ¡õ¡õ¡õ¡õ¡õ¡õ¡õóô¡õóöóõ¡õ¡õ¡õóø¡õ¡õ¡õ¡õ¡õ¡õ¡õôÜ¡õ¡õ¡õ¡õ¡õ¡õçÈ¡õ¡õ¡õ¡õ¡õ¡õ¡õçÄ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÅÕñð¡õ¡õì¢¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ¡¡õ¡õ¡õ¡õ¡õÜé",
"¡õÝÛÞ¨¡õÝÞ¡õ¡õ¡õ¡õ¡õ¡õ¡õÜñ¡õ¡õÝµ¡õ¡õÜ¼¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õó¥òû¡õó¢¡õ¡õ¡õ¡õ¡õ¡õó£¡õ¡õ¡õòÏ¡õ¡õ¡õ¡õ¡õ¡õå½¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÐúÚ»¡õ¡õ¡õ¡õÚÊÚÌ¡õ¡õ¡õÚÒ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõÞ¡õ¡õ¡õõáõäÓâ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛ¦¡õõ­õ¯õ®¡õ¡õ¡õïÃïÄïº¡õÕàïª¡õï¼¡õï¹ï¾îÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õãÕ¡õãÐÑË¡õãÑãÓ¡õãÔ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷´¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ²µ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷Û¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õöÖöØ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õð¶¡õ¡õ¡õ¡õð·÷æ¡õ÷å¡õ¡õ¡õ¡õ¡õ¡õ÷ü¡õ¡õ¡õ¡õ¡õ¡õ¡õàêßâ¡õàã¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õæÕ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õáÚàü¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâû¡õ±÷¡õ¡õ¡õß©¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õéÝ¡õèß¡õ¡õ¡õ¡õ¡õ¡õéÕ",
"¡õ¡õ¡õ¡õéÛ¡õ¡õ¡õ¡õ¡õ¡õ¡õ½©¡õ¡õí´¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâ´¡õ¡õ¡õè´¡õ¡õ¡õ¡õ¡õ¡õêµ¡õê´¡õñª¡õð÷ðïð«¡õî¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíÍ¡õ¡õ¡õíáíâ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õóü¡õóå¡õ¡õ¡õ¡õóþóÙ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õôÝçÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õôí¡õ¡õ¡õ÷ãôê¡õ¡õóÁ¡õîÀ¡õ¡õ¡õñïëþ¡õëûëý¡õ¡õ¡õ¡õ¡õô½¡õ¡õ¡õÞ²¡õ¡õ¡õ¡õ¡õÞ®Þ¯¡õ¡õ",
"Ý÷¡õ¡õ¡õÞª¡õ¡õ¡õ¡õ¡õ¡õÌê¡õ¡õ¡õ¡õÜöÞ¶Þ³¡õ¡õ¡õ¡õ¡õ¡õ¡õó¤¡õ¡õó©¡õóª¡õ¡õ¡õ¡õ¡õ¡õ¡õòüÕÝó±¡õ¡õ¡õ¡õó®¡õ¡õ¡õñÍ¡õ¡õñß¡õ¡õ¡õ¡õêí¡õ¡õì²¡õ¡õÚÕ¡õÖß¡õ¡õ¡õ¡õ¡õåÀ¡õ¡õ¡õ¡õ¡õÚÖ¡õ¡õ¡õ¡õ¡õ¡õõù¡õ¡õ¡õ¡õ¡õ¡õõÄå¿¡õ¡õ¡õ¡õ¡õÃÑõ°È©¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õïÊ¡õïÇÕëÕ¡¡õïÈ¡õ¡õ¡õ¡õ¡õöÌ¡õöÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãÖ¡õ¡õ¡õÚô¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâ¼¡õ¡õ¡õ¡õ¡õÙå¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷ÌöÚ¡õöÜ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õð¹¡õ¡õð»¡õð¼¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíêö½¡õ¡õ÷÷ö³Ùß¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÄö¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õí¡¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞó¡õ¡õ¡õ¡õß£¡õ¡õ¡õêÖ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õìò¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õäÞ¡õ¡õ¡õ¡õ¡õäóãø¡õ¡õ¡õ¡õìÞ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õê¶ñ°ðÜ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíä¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õô¡¡õ¡õô£¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õçÀ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñù¡õ¡õ¡õô¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÝ£¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ¸¡õ¡õ¡õ¡õ¡õó²¡õó³ó¨¡õ¡õ¡õ¡õ¡õó­¡õ¡õò±¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñÐ¡õ¡õ¡õÚ©¡õ¡õ¡õ¡õ¡õÃ¡¡õ¡õ¡õö¥¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõø¡õØÓêÞ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÔã",
"¡õ¡õ¡õ¡õõ¿¡õê¤¡õ¡õ¡õ¡õÚ÷¡õ¡õ¡õ¡õ¡õõµõ²ïØ¡õ¡õ¡õ¡õ¡õ¡õîø¡õïË¡õïÖ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãÄ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷¶¡õ¡õ¡õ¡õ¡õè¸¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâ¾¡õæë¡õ¡õæì¡õ¡õ¡õæí¡õ¡õ÷Â¡õ÷Ü¡õ¡õ¡õ¡õ¡õ¡õ¡õöé¡õ¡õ¡õöá¡õ¡õ¡õ¡õ¡õ¡õ¡õðÃð¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õðÁ¡õ¡õ¡õ¡õ¡õ¡õ÷ð¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õØÉ¡õ¡õß¿¡õ¡õ¡õÛä¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õß«¡õ¡õ¡õ¡õ¡õ¡õéÆ¡õ¡õ¡õ¡õ¡õèÝ¡õ¡õéÍ¡õ¡õéÚ¡õ¡õëª¡õãñäë¡õ¡õ¡õ¡õå¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíç¡õ¡õíæ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õçØ¡õçÙ¡õ¡õ¡õ¡õ¡õ¡õ¡õî¼¡õ¡õ¡õ¡õ¡õ¡õô¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ¼¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙùòÉ¡õ¡õ¡õ¡õò²¡õ¡õ¡õó¹¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñÏ¡õ¡õêï¡õö£¡õ¡õ¡õ¡õ¡õÚÚ×«¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ²ä¡õ¡õ¡õõì¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõ³ïÞïà¡õ¡õ¡õ¡õïê¡õïÒ¡õï¡¡õöË¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õè¹¡õ¡õòª¡õ¡õ¡õ¡õ¡õ¡õâÊ¡õâÉ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷Ä¡õ¡õ¡õ¡õ¡õöìöí¡õ¡õöï¡õöòöóöööß¡õ¡õ¡õ¡õ¡õöî¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õµñ¡õ¡õ¡õ¡õ¡õðÇ¡õ¡õð´¡õ¡õ¡õ¡õíë¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",
"¡õà·¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞü¡õ¡õ¡õ¡õ¡õ¡õèÐ¡õèÀèÓ¡õ¡õ¡õ¡õ¡õå¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õå®¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õâ¨è·¡õ¡õ¡õ¡õ¡õ¡õ¡õÛÇ¡õ¡õ¡õ¡õ¡õíå¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õç×¡õ¡õ¡õ¡õñ÷¡õ¡õÐÆô¿¡õÜ×Þ½¡õ¡õ¡õ¡õÜÂÞ­¡õÞ¿¡õ¡õ¡õòÓòî¡õó·ó¶¡õñà¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ»Ù¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÛ¹¡õ¡õõ¶¡õ¡õï¦ïæ¡õïè¡õïâ¡õ¡õÁÍ¡õïë¡õîü¡õïä¡õ¡õ¡õï©¡õ¡õ¡õ¡õ¡õ",
"¡õ¡õ¡õ¡õ¡õãÛ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õò©¡õ¡õ¡õ¡õ¡õ¡õ¡õâÍÀ¡¡õ¡õ¡õ¡õ¡õ¡õæã¡õæòæóæï¡õ¡õ¡õ¡õ¡õ¡õ¡õöø¡õ¡õöû¡õ¡õ¡õ¡õ¡õ¡õ¡õöü¡õ¡õ¡õ¡õ¡õðÉ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õðÊ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷ô¡õ÷ó¡õ¡õ¡õ¡õö¶¡õ¡õöµ¡õÙÐ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¿ù¡õ¡õ¡õß¥¡õ¡õ¡õé·¡õããäÜ¡õ¡õ¡õ¡õ¡õìß¡õ¡õâµ¡õ¡õ¡õ¡õíÃ¡õ¡õ¡õ¡õæþ¡õçÓ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÞ¾¡õ¡õ¡õÞÀÝü¡õ",
"¡õ¡õóº¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêá¡õ¡õ¡õ¡õ¡õ¡õ¡õÛº¡õ¡õ¡õïî¡õ»·¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãË¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õì­¡õ¡õ¡õ¡õ¡õ¡õæõæîæñ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õöå÷£÷¥¡õ¡õ¡õ¡õðÏ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷½¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õõº¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÙæ¡õ¡õ¡õæ®¡õ¡õ¡õ¡õ¡õ¡õÔÜ¡õ¡õ¡õë¬¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õñ¨¡õ¡õ¡õð¦¡õ¡õóê¡õ¡õ¡õ",
"Ùá¡õ¡õ¡õ¡õ¡õôµ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õêë¡õ¡õÚÙ¡õ¡õ¡õ¡õ¡õ¡õõéõðõÑõÈõñ¡õ¡õ¡õéö¡õïÙ¡õïì¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷Ó¡õ¡õ¡õ¡õ¡õæö¡õæè¡õ¡õ¡õ¡õ¡õ¡õå÷¡õ¡õ¡õ÷¨¡õ¡õöä÷¦¡õ¡õöæ¡õ÷¡¡õ¡õ¡õ¡õ¡õðÒ¡õ¡õ¡õ¡õ¡õ¡õðº¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õíèºÍ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õß¬¡õ¡õ¡õèïé¡¡õ¡õ¡õ¡õ¡õ¡õ¡õÓ¸¡õ¡õ¡õ¡õ¡õÝñ¡õ¡õÞÂ¡õ¡õ¡õ¡õîÃ¡õ¡õ¡õ¡õ¡õ¡õ",
"ÑçöÅ¡õ¡õ¡õ¡õ¡õéñ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷ß¡õ÷®öà¡õ¡õöÑ¡õ¡õ¡õ¡õ¡õ¡õ¡õðÓ¡õ¡õðÖ¡õ¡õ¡õ¡õðÔðÕ¡õ¡õ¡õðÂ¡õ¡õ¡õ¡õ¡õ÷õ¡õ¡õ¡õ¡õ÷û¡õ¡õì´¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õå°¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õóý¡õ¡õ¡õ¡õ¡õó½¡õ¡õ¡õÀ¾õó¡õ¡õ¡õ¡õ¡õ¡õöÎ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ÷Æ¡õ¡õ÷¯¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õàìß­¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õóÖ¡õ¡õ¡õ",
"çÚôî¡õÙõ¡õ¡õ¡õ¡õ¡õ¡õ¡õñá¡õ¡õ¡õ´Ú¡õ¡õ¡õïç¡õ¡õ¡õ¡õ¡õâÃ¡õ¡õöÝ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õö¾¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õôõõòõ§¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õÚÝ¡õ¡õ¡õ¡õò¨È§¡õ¡õ¡õæø¡õ¡õ¡õðµ¡õ¡õí°¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õãÎ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õöâð¿äÙ¡õ¡õ¡õ¡õ¡õ¡õ¡õÀï¡õ¡õ¡õ¡õ©³¡õ©·¡õ¡õ¡õ©»©ß©¿¡õ¡õ¡õ©Á©ã©É¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ©§©¥¡õ¡õ¡õ¡õ¡õ"
});

string b5_gb(string str)
{
    int i, len, hi, lo;
	string ret = "";

	if (!stringp(str)) return ret;
	len = strlen(str);
    for (i=0;i<len;i++) {
        hi = str[i];
        if (hi < 161 || hi > 249) {
		ret += " ";
		ret[<1] = hi;
		continue;
	}
        lo = str[i+1];
        if (lo < 64 || lo > 254) continue;
        if (lo > 126 && lo < 161) continue;
        lo -= 64; if (lo > 96) lo -= 34;
        lo += lo;
        ret += b5[hi-161][lo..lo+1];
        i++;
    }
    return ret;
}

string gb_b5(string str)
{
    int i, len, hi, lo;
	string ret = "";

	if (!stringp(str)) return ret;
	len = strlen(str);
    for (i=0;i<len;i++) {
        hi = str[i];
        if (hi < 161 || hi > 247) {
		ret += " ";
		ret[<1] = hi;
		continue;
	}
        lo = str[i+1];
        if (lo < 161 || lo > 254) continue;
        lo -= 161;
        lo += lo;
        ret += gb[hi-161][lo..lo+1];
        i++;
    }
    return ret;
}
