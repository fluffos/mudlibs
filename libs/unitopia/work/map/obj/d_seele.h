
void notify_seele(object wer, mixed wen, string befehl, string adverb,
    int align, int flags, int msg_typ_wer, int msg_typ_wen, int msg_typ_andere)
{
  if(wen!=this_object())
    return;
  switch (befehl) {
    case "knuddel"   : call_out("message",2,
                       wrap(Der()+" laesst sich "+des(wer)+" Knuddelei "
                                  "quietschend gefallen."),
                       wrap(Der()+" laesst sich Deine Knuddelei "
                                  "quietschend gefallen."),wer);
                       break;
    case "umarm"     : call_out("message",2,
                       wrap(Der()+" laesst sich "+des(wer)+
                                  " Umarmung quietschend gefallen."),
                       wrap(Der()+" laesst sich Deine Umarmung "
                                  "quietschend gefallen."),wer);
                       break;
    case "stups"     : call_out("message",2,
                       wrap(Der()+" stupst "+den(wer)+" mit seiner "
                                  "spitzen Schnauze."),
                       wrap(Der()+" stupst Dich sanft mit seiner "
                                  "spitzen Schnauze."),wer);
                       break; // vielleicht doch lieber
                              // abfangen - wegen der Nase!?
    case "streichel" : call_out("message",2,
                       wrap(Der()+" scheint das Streicheln zu geniessen."),
                       wrap(Der()+" dreht sich so, dass Du ihn besser "
                            "streicheln kannst und geniesst schweigend."),wer);
                       break;
    case "taetschel" : call_out("message",2,
                       wrap(Der()+" versucht, "+dem(wer)+" weitere "
                                  "Zaertlichkeiten abzuringen."),
                       wrap(Der()+" dreht sich so, dass Du ihn bequem "
                                  "streicheln koenntest."),wer);
                       break;
    case "schmieg"   : call_out("message",2,
                       wrap(Der()+" draengt sich uebereifrig an "+den(wer)+
                            " und taucht "+ihn(wer)+" dabei unter Wasser."),
                       wrap(Der()+" taucht Dich beim Versuch, sich wiederum "
                            "an Dich zu schmiegen, ein Stueck unter "
                            "Wasser."),wer);
                       break;
    case "kitzel"    : call_out("message",2,
                       wrap(Der()+" knufft "+den(wer)+" in die Seite."),
                       wrap(Der()+" knufft Dich frech mit seiner Schnauze "
                                  "in die Seite."),wer);
                       break;
    case "kuschel"   : call_out("message",2,
                       wrap(Der()+" versucht, "+den(wer)+" mit energischen "
                                  "Stoessen seiner spitzen Schnauze zum "
                                  "Streicheln aufzufordern."),
                       wrap(Der()+" fordert Dich mit energischen Stoessen "
                                  "seiner spitzen Schnauze auf, ihn "
                                  "nun auch noch zu streicheln."),wer);
                       break;
    case "drueck"    : call_out("message",2,
                       wrap(Der(wer)+" wird von "+dem()+" ein Stueck durchs "
                            "Wasser geschoben."),
                       wrap(Der()+" schiebt Dich ein Stueck durchs Wasser "
                            "als er seinen Koerper an Dich drueckt."),wer);
                       break;
    case "schmus"    : call_out("message",2,
                       wrap(Der()+" versucht, "+den(wer)+" mit energischen "
                                  "Stoessen seiner spitzen Schnauze zum "
                                  "Streicheln aufzufordern."),
                       wrap(Der()+" fordert Dich mit energischen Stoessen "
                                  "seiner spitzen Schnauze auf, ihn "
                                  "nun auch noch zu streicheln."),wer);
                       break;
    default          : call_out("message",2,
                       wrap(Der()+" schaut "+den(wer)+" aufmerksam an."),
                       wrap(Der()+" schaut Dich aufmerksam an."),wer);
                       break;
    }
}

int forbidden_seele(object wer, mixed wen, string befehl, string adverb,
    int align, int flags, int msg_typ_wer, int msg_typ_wen, int msg_typ_andere)
{
  if(wen!=this_object())
    return 0;
  switch(befehl) {

    case "quael"   : write(wrap("Du versuchst, ueble Scherze mit "
                                +dem()+" zu treiben, doch er "
                                " vereitelt dies, indem er "
                                " einfach davonschwimmt."));
                     say(wrap(Der(wer)+" versucht, ueble Scherze "
                              "mit "+dem()+" zu treiben, doch er "
                              " vereitelt dies, indem er "
                              " einfach davonschwimmt."),wer);
                     return 1;
    case "tritt"   : write(wrap("Du versuchst, im Wasser nach "
                                +dem()+" zu treten, wobei Dir ploetzlich "
                                "bewusst wird, wie laecherlich das "
                                "wirken muss."));
                     say(wrap(Der(wer)+" strampelt hektisch mit den Beinen "
                              "im Wasser."),wer);
                     return 1;
    case "zwick"   : write(wrap("Du zwickst "+den()+" in die "
                                "Schnauze."));
                     write(wrap(Der()+" knufft Dich frech mit seiner "
                                "Schnauze in die Seite."));
                     say(wrap(Der(wer)+" zwickt "+den()+
                                       " in die Schnauze."),wer);
                     say(wrap(Der()+" knufft "+den(wer)+
                                    " in die Seite."),wer);
                     return 1;

    case "entmann" : write(wrap("Du hebst Dein Knie in Richtung "+des()+"."));
                     say(wrap(Der(wer)+" vollfuehrt merkwuerdige Bewegungen "
                                       "im Wasser."),wer);
                     return 1;

    case "hau"     : write(wrap("Du versuchst vergeblich, "+den()+" mit "
                                "Deinen Faeusten zu treffen."));
                     say(wrap(Der(wer)+" fuchtelt wie wild mit den Haenden "
                                       "im Wasser."),wer);
                     return 1;
    case "kneif"   : write(wrap("Du kneifst "+den()+"."));
                     write(wrap(Der()+" knufft Dich frech mit seiner Schnauze "
                                      "in die Seite."));
                     say(wrap(Der(wer)+" kneift "+den()+"."),wer);
                     say(wrap(Der()+" knufft "+den(wer)+" in die Seite."),wer);
                     return 1;

    case "wuerg"   : write(wrap("Du versuchst, "+den()+" zu wuergen, "
                                 "doch er entwischt Dir blitzschnell."));
                     say(wrap(Der(wer)+" versucht, "+den()+" zu wuergen, "
                              "doch er entwischt "+ihm(wer)+
                              " blitzschnell."),wer);
                     return 1;

    case "wuschel" : write(wrap("Da "+der()+" keinerlei Haare besitzt, "
                                "kannst Du bei ihm auch nichts "
                                "verwuscheln."));
                     return 1;

    default        : return 0;
    }
}
