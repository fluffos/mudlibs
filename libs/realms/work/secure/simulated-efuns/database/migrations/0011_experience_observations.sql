CREATE TABLE IF NOT EXISTS `experienceObservations` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `observationType` varchar(80) NOT NULL,
  `actor` varchar(200) NOT NULL,
  `subject` varchar(200) DEFAULT NULL,
  `participants` text,
  `observationTime` bigint NOT NULL DEFAULT '0',
  `location` varchar(255) DEFAULT NULL,
  `observationContext` mediumtext,
  `observationMetadata` mediumtext,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `experience_playerId_idx` (`playerId`),
  KEY `experience_observationType_idx` (`observationType`),
  CONSTRAINT `experience_playerid` FOREIGN KEY (`playerId`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS `pruneExperience`;
##
CREATE PROCEDURE `pruneExperience` (p_playerid int)
BEGIN
	DELETE FROM experienceObservations WHERE playerId = p_playerid;
END;
##
DROP PROCEDURE IF EXISTS `saveExperienceObservation`;
##
CREATE PROCEDURE `saveExperienceObservation` (
	p_playerid int,
	p_observationType varchar(80),
	p_actor varchar(200),
	p_subject varchar(200),
	p_participants text,
	p_observationTime bigint,
	p_location varchar(255),
	p_context mediumtext,
	p_metadata mediumtext)
BEGIN
	INSERT INTO experienceObservations (
		playerId,
		observationType,
		actor,
		subject,
		participants,
		observationTime,
		location,
		observationContext,
		observationMetadata)
	VALUES (
		p_playerid,
		p_observationType,
		p_actor,
		p_subject,
		p_participants,
		p_observationTime,
		p_location,
		p_context,
		p_metadata);
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
