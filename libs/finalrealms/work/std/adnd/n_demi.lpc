Received: From SOFUS/MAILQUEUE by odin.dhhalden.no
          via Charon-4.0-VROOM with IPX id 102.921218234828.288;
          18 Dec 92 23:48:37 -100
Received: From fenris.dhhalden.no by odin.dhhalden.no
          via Charon-4.0-VROOM with SMTP id 102.921218234828.288;
          18 Dec 92 23:48:27 -100
Received: from alf.uib.no by fenris.dhhalden.no with SMTP (PP) 
          id <07184-0@fenris.dhhalden.no>; Fri, 18 Dec 1992 23:48:18 +0100
Received: from livid.uib.no by alf.uib.no with SMTP (PP) 
          id <02331-0@alf.uib.no>; Fri, 18 Dec 1992 23:47:58 +0100
Received: from NOBERGEN.UIB.NO by lilje.uib.no (IBM VM SMTP V2R2) with BSMTP 
          id 4454; Fri, 18 Dec 92 23:47:19 EMT
Received: from UTMARTNV.BITNET (NJE origin MAILER@UTMARTNV) 
          by NOBERGEN.UIB.NO (LMail V1.1a/1.7e) with BSMTP id 4453;
          Fri, 18 Dec 1992 23:47:19 +0100
Received: from UTMARTN (MUSIC) by UTMARTNV.BITNET (Mailer R2.08 R208004) 
          with BSMTP id 4734; Fri, 18 Dec 92 16:49:06 CST
Message-Id: <18DEC92.18163314.0056.MUSIC@UTMARTN>
Date: Fri, 18 Dec 92 16:49:04 CST
From: Eric Lemings <WA11%UTMARTN.bitnet@livid.uib.no>
To: Haavard Hoeyaas Kristoffersen <HAVARDHK@DHHALDEN.NO>, 
    Dan Kindsavter <DANK@ROCK.CONCERT.NET>, ? <DARIO@FOGHORN.CC.UTEXAS.EDU>
Subject: demihuman.c

/* AD&D, 2nd Edition (c) Player Character Races -- Demihuman */

inherit "/std/race";

string *langRstr;
mapping classLimit;
int *thiefSkillAdj;

string *GetLangRstr(void) { return (langRstr); }

int CheckLangRstr(string lang) {
  return (member_array(langRstr, lang) >= 0);
}

void GetThiefSkillAdj(int *thiefSkill)
{
  int i;

  for (i = 0; i < 8; i++)
    thiefSkill[i] += thiefSkillAdj[i];
}

int GetClassLimit(string className) {
  return (classLimit[className]);
}

int SavingThrowBonus(void)
{
  int con = this_player()->GetAbilityScore(CON);

  return (con * 2 / 7);
}


