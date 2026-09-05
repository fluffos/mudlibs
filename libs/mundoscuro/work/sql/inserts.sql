INSERT INTO jugadores VALUES ('cain','a','a','a',0);
INSERT INTO jugadores VALUES ('cloud','a','a','a',0);
INSERT INTO jugadores VALUES ('shotgan','a','a','a',0);
INSERT INTO jugadores VALUES ('vhalar','a','a','a',0);
INSERT INTO jugadores VALUES ('sutxo','a','a','a',0);
INSERT INTO jugadores VALUES ('erunak','a','a','a',0);
INSERT INTO jugadores VALUES ('link','a','a','a',0);
INSERT INTO jugadores VALUES ('jotabe','a','a','a',0);
INSERT INTO jugadores VALUES ('raysha','a','a','a',0);
INSERT INTO jugadores VALUES ('phooka','a','a','a',0);
INSERT INTO jugadores VALUES ('niyara','a','a','a',0);
INSERT INTO jugadores VALUES ('mave','a','a','a',0);

INSERT INTO grupos VALUES (NULL, 'noone');
INSERT INTO grupos VALUES (NULL, 'creador');
INSERT INTO grupos VALUES (NULL, 'semidios');
INSERT INTO grupos VALUES (NULL, 'dios');
INSERT INTO grupos VALUES (NULL, 'admin');
INSERT INTO grupos VALUES (NULL, 'guild');
INSERT INTO grupos VALUES (NULL, 'domain');
INSERT INTO grupos VALUES (NULL, 'highlord');
INSERT INTO grupos VALUES (NULL, 'aira');
INSERT INTO grupos VALUES (NULL, 'essadath');
INSERT INTO grupos VALUES (NULL, 'oniria');
INSERT INTO grupos VALUES (NULL, 'avalon');

INSERT INTO rangos VALUES ('admin',1000);
INSERT INTO rangos VALUES ('creador',100);
INSERT INTO rangos VALUES ('semidios',250);
INSERT INTO rangos VALUES ('dios',500);

INSERT INTO inmortales VALUES (NULL, 'cain', 'admin');
INSERT INTO inmortales VALUES (NULL, 'jotabe', 'semidios');
INSERT INTO inmortales VALUES (NULL, 'vhalar', 'dios');
INSERT INTO inmortales VALUES (NULL, 'sutxo', 'semidios');
INSERT INTO inmortales VALUES (NULL, 'link', 'creador');
INSERT INTO inmortales VALUES (NULL, 'niyara', 'creador');
INSERT INTO inmortales VALUES (NULL, 'phooka', 'dios');

INSERT INTO miembros VALUES ('cain', 'admin');
INSERT INTO miembros VALUES ('jotabe', 'semidios');
INSERT INTO miembros VALUES ('vhalar', 'dios');
INSERT INTO miembros VALUES ('sutxo', 'semidios');
INSERT INTO miembros VALUES ('link', 'creador');
INSERT INTO miembros VALUES ('niyara', 'creador');
INSERT INTO miembros VALUES ('phooka', 'dios');
INSERT INTO miembros VALUES ('phooka', 'highlord');
INSERT INTO miembros VALUES ('cain', 'highlord');
INSERT INTO miembros VALUES ('vhalar', 'avalon');
INSERT INTO miembros VALUES ('sutxo', 'domain');
INSERT INTO miembros VALUES ('jotabe', 'guild');

