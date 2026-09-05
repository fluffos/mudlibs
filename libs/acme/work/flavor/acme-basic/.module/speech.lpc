/**
 * Support for items capable of communication by speech.
 *
 * @author devo@eotl
 * @alias SpeechMixin
 */

#define SpeechBinDir       BinDir "/speech"

mapping spoken_languages;

struct MessageResult {
  object *received, *rejected;
  mapping msgdata;
};

struct MessageResult say(string msg, mapping msgdata) {
  if (member(msgdata, MSGDATA_TOPIC)) {
    // TODO log warning
  }
  msgdata[MSGDATA_TOPIC] = TopicService->get_environment_topic(ENV(THISO));

  if (!member(msgdata, MSGDATA_LANGUAGE)) {
    // TODO add default language preference
  }
  if (!member(msgdata, MSGDATA_LANGUAGE)) {
    // TODO error
  }


  msgdata[]
  {
    language: string english,
    senses: int sound bitvector,
    volume: float NN vu
    topic: string rooms.zone.blah.foo.fart, stuff.zone.some.container, stuff.zone.some.carrier
  }
  // tell_object(map)
}

object *shout(string msg, mapping msgdata) {
  // none, room, room+1, room+2, zone, zone+1, zone+2, domain, domain+1, domain+2, ...
}

object *whisper(mixed target, string msg, mapping msgdata) {
  // target is string topic or object *who
}

mapping query_spoken_languages() {
  return spoken_languages;
}

void set_spoken_languages(mapping language) {
  spoken_languages = language;
}

void add_spoken_language(string language) {
  spoken_languages += ([ language ]);
}

void remove_spoken_language(string language) {
  spoken_languages -= ([ language ]);
}

int is_language_spoken(string language) {
  return member(spoken_languages, language);
}

protected void setup_speech() {
  spoken_languages = ([ "default" ]);
}

/**
 * Return the CommandCode commands that will be made available to
 * implementors of this mixin. This will be invoked by objects implementing
 * CommandGiverMixin for each inherited blueprint.
 *
 * @return an array of paths to CommandCode objects
 */
public string *query_command_imports(object command_giver) {
  return ({
    SpeechBinDir "/say",
    SpeechBinDir "/shout",
    SpeechBinDir "/whisper"
  });
}
