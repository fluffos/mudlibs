CREATE TABLE IF NOT EXISTS `relationships` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `targetKey` varchar(255) NOT NULL,
  `updated` bigint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `relationship_unique` (`playerId`, `targetKey`),
  CONSTRAINT `relationships_playerid` FOREIGN KEY (`playerId`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE IF NOT EXISTS `relationshipDimensions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `relationshipId` int(11) NOT NULL,
  `dimension` varchar(80) NOT NULL,
  `value` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `relationship_dimension_unique` (`relationshipId`, `dimension`),
  CONSTRAINT `relationshipDimensions_relationshipid` FOREIGN KEY (`relationshipId`) REFERENCES `relationships` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE IF NOT EXISTS `relationshipHistory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `relationshipId` int(11) NOT NULL,
  `dimension` varchar(80) NOT NULL,
  `delta` int(11) NOT NULL DEFAULT '0',
  `value` int(11) NOT NULL DEFAULT '0',
  `timestamp` bigint NOT NULL DEFAULT '0',
  `producer` varchar(255) DEFAULT NULL,
  `context` mediumtext,
  `metadata` mediumtext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `relationshipHistory_relationshipid` FOREIGN KEY (`relationshipId`) REFERENCES `relationships` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS `pruneRelationships`;
##
CREATE PROCEDURE `pruneRelationships` (p_playerid int)
BEGIN
	DELETE FROM relationshipHistory
	WHERE relationshipId IN
		(SELECT id FROM relationships WHERE playerId = p_playerid);

	DELETE FROM relationshipDimensions
	WHERE relationshipId IN
		(SELECT id FROM relationships WHERE playerId = p_playerid);

	DELETE FROM relationships WHERE playerId = p_playerid;
END;
##
DROP PROCEDURE IF EXISTS `saveRelationship`;
##
CREATE PROCEDURE `saveRelationship` (
	p_playerid int,
	p_targetKey varchar(255),
	p_updated bigint)
BEGIN
	DECLARE l_relationshipId int;

	SELECT id INTO l_relationshipId
	FROM relationships
	WHERE playerId = p_playerid AND targetKey = p_targetKey;

	IF l_relationshipId IS NULL THEN
		INSERT INTO relationships (playerId, targetKey, updated)
		VALUES (p_playerid, p_targetKey, p_updated);
	ELSE
		UPDATE relationships
		SET updated = p_updated
		WHERE id = l_relationshipId;
	END IF;
END;
##
DROP PROCEDURE IF EXISTS `saveRelationshipDimension`;
##
CREATE PROCEDURE `saveRelationshipDimension` (
	p_playerid int,
	p_targetKey varchar(255),
	p_dimension varchar(80),
	p_value int)
BEGIN
	DECLARE l_relationshipId int;
	DECLARE l_dimensionId int;

	SELECT id INTO l_relationshipId
	FROM relationships
	WHERE playerId = p_playerid AND targetKey = p_targetKey;

	IF l_relationshipId IS NOT NULL THEN
		SELECT id INTO l_dimensionId
		FROM relationshipDimensions
		WHERE relationshipId = l_relationshipId AND dimension = p_dimension;

		IF l_dimensionId IS NULL THEN
			INSERT INTO relationshipDimensions (relationshipId, dimension, value)
			VALUES (l_relationshipId, p_dimension, p_value);
		ELSE
			UPDATE relationshipDimensions
			SET value = p_value
			WHERE id = l_dimensionId;
		END IF;
	END IF;
END;
##
DROP PROCEDURE IF EXISTS `saveRelationshipHistory`;
##
CREATE PROCEDURE `saveRelationshipHistory` (
	p_playerid int,
	p_targetKey varchar(255),
	p_dimension varchar(80),
	p_delta int,
	p_value int,
	p_timestamp bigint,
	p_producer varchar(255),
	p_context mediumtext,
	p_metadata mediumtext)
BEGIN
	DECLARE l_relationshipId int;

	SELECT id INTO l_relationshipId
	FROM relationships
	WHERE playerId = p_playerid AND targetKey = p_targetKey;

	IF l_relationshipId IS NOT NULL THEN
		INSERT INTO relationshipHistory
			(relationshipId, dimension, delta, value, timestamp,
			 producer, context, metadata)
		VALUES
			(l_relationshipId, p_dimension, p_delta, p_value, p_timestamp,
			 p_producer, p_context, p_metadata);
	END IF;
END;
##
DROP PROCEDURE IF EXISTS removePlayer;
##
CREATE PROCEDURE `removePlayer` ( p_name varchar(40) )
BEGIN
	declare localUserId int;
	declare localPlayerId int;
	declare characterCount int;

	select id, userId into localPlayerId, localUserId
	from players where name = p_name;

	if localPlayerId is not null then
		delete from biological where playerId = localPlayerId;
		delete from combatStatistics where playerId = localPlayerId;
		delete from combatStatisticsForRace where playerId = localPlayerId;
		delete from guilds where playerId = localPlayerId;
		delete from materialAttributes where playerId = localPlayerId;
		delete from playerCombatData where playerId = localPlayerId;
		delete from quests where playerId = localPlayerId;
		delete from wizards where playerId = localPlayerId;
		delete from skills where playerId = localPlayerId;
		delete from factions where playerId = localPlayerId;
		delete from inventory where playerId = localPlayerId;
		delete from opinions where playerId = localPlayerId;
		delete from characterStates where playerId = localPlayerId;
		delete from settings where playerId = localPlayerId;
		delete from parties where creatorid = localPlayerId;
		delete from playerRoles where playerid = localPlayerId;
		delete from npcs where playerid = localPlayerId;
		delete from experienceObservations where playerId = localPlayerId;
		call pruneRelationships(localPlayerId);
		call removeConstructedResearch(localPlayerId);
		call removeCompositeResearch(localPlayerId);
		call removeResearch(localPlayerId);
		call removeTraits(localPlayerId);
		call removeDomains(localPlayerId);

		delete from players where id = localPlayerId;

		if localUserId is not null then
			select count(id) into characterCount
			from players where userId = localUserId;

			if characterCount = 0 then
				delete from users where id = localUserId;
			end if;
		end if;
	end if;
END;
