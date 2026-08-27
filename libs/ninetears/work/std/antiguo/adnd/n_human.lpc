Received: From SOFUS/MAILQUEUE by odin.dhhalden.no
          via Charon-4.0-VROOM with IPX id 102.921218234807.256;
          18 Dec 92 23:48:14 -100
Received: From fenris.dhhalden.no by odin.dhhalden.no
          via Charon-4.0-VROOM with SMTP id 102.921218234807.256;
          18 Dec 92 23:48:07 -100
Received: from alf.uib.no by fenris.dhhalden.no with SMTP (PP) 
          id <07168-0@fenris.dhhalden.no>; Fri, 18 Dec 1992 23:47:57 +0100
Received: from livid.uib.no by alf.uib.no with SMTP (PP) 
          id <02326-0@alf.uib.no>; Fri, 18 Dec 1992 23:47:48 +0100
Received: from NOBERGEN.UIB.NO by lilje.uib.no (IBM VM SMTP V2R2) with BSMTP 
          id 4452; Fri, 18 Dec 92 23:47:10 EMT
Received: from UTMARTNV.BITNET (NJE origin MAILER@UTMARTNV) 
          by NOBERGEN.UIB.NO (LMail V1.1a/1.7e) with BSMTP id 4451;
          Fri, 18 Dec 1992 23:47:10 +0100
Received: from UTMARTN (MUSIC) by UTMARTNV.BITNET (Mailer R2.08 R208004) 
          with BSMTP id 4728; Fri, 18 Dec 92 16:48:55 CST
Message-Id: <18DEC92.18159036.0056.MUSIC@UTMARTN>
Date: Fri, 18 Dec 92 16:48:49 CST
From: Eric Lemings <WA11%UTMARTN.bitnet@livid.uib.no>
To: Haavard Hoeyaas Kristoffersen <HAVARDHK@DHHALDEN.NO>, 
    Dan Kindsavter <DANK@ROCK.CONCERT.NET>, ? <DARIO@FOGHORN.CC.UTEXAS.EDU>
Subject: human.c

/* AD&D, 2nd Edition (c) Player Character Races -- Human */

inherit "/std/race";

void create(void)
{
  race::create();
  raceName = subName = "human";
  mBaseHt = 60, fBaseHt = 59;
  mBaseWt = 140, fBaseWt = 100;
  htAdj = ({ 19, 2 }), wtAdj = ({ 55, 6 });
  startingAge = 15, middleAge = 45;
  oldAge = 60, venerableAge = 90;
  startAgeAdj = ({ 4, 1 }), maxAgeAdj = ({ 39, 2 });
  classRstr = ({ "fighter", "paladin", "ranger", "mage", "abjurer",
    "conjurer", "diviner", "enchanter", "illusionist", "invoker",
    "necromancer", "transmuter", "cleric", "druid", "thief", "bard" });
  lightRqr = 20;
}

int ActivateClass(void) {
  return 1;        /* humans get no racial powers */
}


