// /d/gebirge/feyaria/weg/room/weide.h
// Allgemeine Details fuer die Schafweide
// 1996-01-01 Feyaria@SilberLand


#define P_INT_SHORT_WEIDE						\
  SetProp(P_INT_SHORT, "Auf einer Schafweide");

#define WEIDE								\
SetProp(P_LIGHT, 1);							\
SetProp(P_INDOORS, 0);							\
AddSmell( ({DEFAULT_SMELL, "schaf", "schafe"}),				\
  "Es riecht nach Schafen.");						\
AddDetail( ({"boden", "gras", "graeser", "sauergras", "ernaehrung"}),	\
  "Hier waechst kuemmerliches Sauergras, das der Ernaehrung einer "	\
  "Schafherde dient.");							\
AddDetail( ({"schaf", "schafe", "herde", "schafherde"}),		\
  "Hier weidet eine Schafherde, die von einem Schaefer mit seinen "	\
  "Schaeferhunden bewacht wird.");					\
AddDetail( ({"schaefer", "hirte", "schafhirte", "hund", "schaeferhund"}),\
  "Der ist gerade nicht in Deiner Naehe. Geh doch naeher ran, dann "	\
  "kannst Du viel mehr erkennen.");					\
AddDetail( ({"naehe", "ferne", "wort", "grossgeschriebene", "beruhigung"}),\
  "Untersuchst Du wirklich jedes Grossgeschriebene Wort? Aber zu "      \
  "Deiner Beruhigung: Die Ferne ist weit weg und die Naehe sehr nah!"); \
AddDetail( ({"hochflaeche"}),						\
  "Du stehst auf einer fast ebenen, nach " + CAP(ED3) + " geneigten "	\
  "Hochflaeche. Das karge Gras kann hier wohl keine Kuehe ernaehren, "	\
  "deshalb haelt man hier die genuegsameren Schafe.");			\
AddDetail( ({"kuh", "kuehe", "dinge"}),					\
  "Nicht vorhandene Dinge sollte man eigentlich nicht untersuchen. "	\
  "Hier gibts wirklich keine Kuehe, denn das Gras ist viel zu "		\
  "kuemmerlich.");							\
AddDetail( ({"huegel", "huegellandschaft"}),				\
  "Im "+ CAP(ED7) +" ist das Gelaende sehr huegelig.");			\
AddDetail( ({"himmel", "wolken", "wolke", "sonne", "wind", "wetter"}),	\
  "Im Himmel sind einige Wolken zu sehen, aber trotzdem scheint die "	\
  "Sonne. Es ist aber empfindlich kalt, da ein unangenehmer Wind "	\
  "von den Bergen herunterblaest.");					\

