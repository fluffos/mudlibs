-- Rank/group channels. Upstream seed created grupos via raw SQL,
-- so CANALES->register() never ran. grupos.start() now backfills
-- these at boot; this file is for a fresh MariaDB.
INSERT IGNORE INTO canales (canal, tipo) VALUES
 ('admin',0),('dios',0),('semidios',0),('creador',0),
 ('irc',0),('guild',0),('domain',0),('highlord',0),
 ('aira',0),('essadath',0),('oniria',0),('avalon',0),('noone',0);
