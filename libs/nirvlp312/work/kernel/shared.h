#define SHARED_ACCESS ([ \
  "privileges" : ({ "kernel/server" }), \
  "action_rules" : ({ "global/server/actions" }), \
  "action_rule_cache" : ({ "global/server/actions" }), \
  "action_classes" : ({ "global/server/actions" }), \
  "action_rule_handlers" : ({ "global/server/actions" }), \
  "action_error_handlers" : ({ "global/server/actions" }), \
  "action_handler_last_refreshed" : ({ "global/server/actions" }), \
  "notify_reset" : ({ "global/server/notifier" }), \
  "cron::jobs" : ({ "global/server/cron", "global/server/cron_new" }), \
  "meeting_centre_persons" : ({ "room/adv_centre" }), \
  ])

