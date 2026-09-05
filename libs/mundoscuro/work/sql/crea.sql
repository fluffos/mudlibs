CREATE TABLE jugadores (
	nombre VARCHAR(12) NOT NULL,
	passwd VARCHAR(12) NOT NULL,
	email  VARCHAR(150) NOT NULL,
	codreg CHAR(13) NOT NULL,
	estado INT NOT NULL DEFAULT 0,
	INDEX login (nombre, passwd),
	CONSTRAINT pk_nombre_jugadores PRIMARY KEY (nombre)
) ENGINE=InnoDB;

CREATE TABLE grupos (
	gid INT NOT NULL AUTO_INCREMENT,
	grupo VARCHAR(12) NOT NULL UNIQUE,
	INDEX gid_ind (gid),
	CONSTRAINT pk_gid_grupos PRIMARY KEY (gid)
) ENGINE=InnoDB;

CREATE TABLE rangos (
	rango VARCHAR(25) NOT NULL,
	nivel INT NOT NULL UNIQUE,
	INDEX rango_ind (rango),
	INDEX nivel_ind (nivel),
	CONSTRAINT pk_rango_rangos PRIMARY KEY (rango),
	CONSTRAINT fk_rango_rangos FOREIGN KEY (rango) REFERENCES grupos(grupo) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB;

CREATE TABLE inmortales (
	uid INT NOT NULL AUTO_INCREMENT,
	nombre VARCHAR(12) NOT NULL UNIQUE,
	rango  VARCHAR(12) NOT NULL,
	INDEX uid_ind (uid),
	INDEX nombre_ind (nombre),
	INDEX rango_ind (rango),
	CONSTRAINT pk_uid_inmortales PRIMARY KEY (uid),
	CONSTRAINT fk_nombre_inmortales FOREIGN KEY (nombre) REFERENCES jugadores(nombre) ON DELETE CASCADE,
	CONSTRAINT fk_rango_inmortales FOREIGN KEY (rango) REFERENCES rangos(rango) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE miembros (
	nombre VARCHAR(12) NOT NULL,
	grupo  VARCHAR(12) NOT NULL,
	INDEX nombre_ind(nombre),
	INDEX grupo_ind(grupo),
	CONSTRAINT pk_nombre_grupo_miembros PRIMARY KEY (nombre, grupo),
	CONSTRAINT fk_nombre_miembros FOREIGN KEY (nombre) REFERENCES inmortales(nombre) ON DELETE CASCADE,
	CONSTRAINT fk_grupo_miembros FOREIGN KEY (grupo) REFERENCES grupos(grupo) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE canales (
	cid INT NOT NULL AUTO_INCREMENT,
	canal VARCHAR(12) NOT NULL UNIQUE,
	tipo INT NOT NULL,
 	CONSTRAINT pk_canales PRIMARY KEY (cid)
) ENGINE=InnoDB;

