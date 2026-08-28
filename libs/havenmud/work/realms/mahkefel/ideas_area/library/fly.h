string you_cant_fly = "You see no easy way to reach the balcony from here.";

// used for room exits. Returns true if flying and gives a fly message.
int checkFlying() {

  object who = this_player();
  if (creatorp(who)) {
    who->eventPrint("You walk up the walls. Cheater.");
    return 1;
  }

  if (who->GetRace() == "lamrani") {
    send_messages("levitate",
      "$agent_name $agent_verb upward effortlessly.",
      who, 0, this_object()
    );
    return 1;
  }

  if (who->GetLimb("right wing") && who->GetLimb("left wing")) {
    send_messages("soar",
      "$agent_name $agent_verb upward.",
      who, 0, this_object()
    );
    return 1;
  }

  eventPrint(you_cant_fly);
  return 0;
}

// simply returns true if dude can fly
int canFly(object who) {
  if (who->GetRace() == "lamrani") {
    return 1;
  }

  if (who->GetLimb("right wing") && who->GetLimb("left wing")) {
    return 1;
  }

  return 0;
}
