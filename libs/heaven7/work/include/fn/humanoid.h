#ifndef HUMANOID_H
#define HUMANOID_H

status humanoid(object who) {
  string race_type, str;

  if(!who) return 0;
  race_type = (string)who->query_race();
  if(!race_type) return 0;
  race_type = lower_case(race_type);
  return (sscanf(race_type, "%self%s", race_type, str)
       || sscanf(race_type, "%sdwarf%s", race_type, str)
       || sscanf(race_type, "%sminotaur%s", race_type, str)
       || sscanf(race_type, "%sorc%s", race_type, str)
       || sscanf(race_type, "%sgiant%s", race_type, str)
       || sscanf(race_type, "%shalfling%s", race_type, str)
       || sscanf(race_type, "%skender%s", race_type, str)
       || sscanf(race_type, "%sgnome%s", race_type, str)
       || sscanf(race_type, "%spixie%s", race_type, str)
       || sscanf(race_type, "%snixie%s", race_type, str)
       || sscanf(race_type, "%skobold%s", race_type, str)
       || sscanf(race_type, "%sgoblin%s", race_type, str)
       || sscanf(race_type, "%ssprite%s", race_type, str)
       || sscanf(race_type, "%shuman%s", race_type, str)) ? 1 : 0;
}

#endif
