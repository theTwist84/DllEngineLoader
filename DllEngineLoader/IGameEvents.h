#pragma once

// TODO: finish telemetry prints [	//printf("IGameEvents::(]

class IGameEvents
{
public:
	IGameEvents();
	~IGameEvents();

	/* 000 */	virtual void AchievementEarned(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 AchievementID);
	/* 001 */	virtual void AshesToAshes(LPWSTR UserID, GUID PlayerSessionID);
	/* 002 */	virtual void Assist(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade);
	/* 003 */	virtual void AudioLogClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 AudioLogID);
	/* 004 */	virtual void Base(LPWSTR UserID, GUID PlayerSessionID);
	/* 005 */	virtual void Betrayal(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade);
	/* 006 */	virtual void BIFactControllerSettings(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted);
	/* 007 */	virtual void BIFactDeepLink(LPWSTR UserID, GUID PlayerSessionID);
	/* 008 */	virtual void BIFactDeepLinkRecieve(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL);
	/* 009 */	virtual void BIFactDeepLinkSend(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL);
	/* 010 */	virtual void BIFactDualWield(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp);
	/* 011 */	virtual void BIFactGameSession(LPWSTR UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, LPWSTR HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, LPWSTR LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, LPWSTR HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides);
	/* 012 */	virtual void BIFactLoadout(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID);
	/* 013 */	virtual void BIFactMatchmaking(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID);
	/* 014 */	virtual void BIFactMatchmakingDetails(LPWSTR UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, LPWSTR GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated);
	/* 015 */	virtual void BIFactMedia(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, LPWSTR MediaID);
	/* 016 */	virtual void BirdOfPrey(LPWSTR UserID, GUID PlayerSessionID);
	/* 017 */	virtual void BitsAndPiecesDestroyed(LPWSTR UserID, GUID PlayerSessionID);
	/* 018 */	virtual void BroadcastingAssist(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists);
	/* 019 */	virtual void BroadcastingDeath(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths);
	/* 020 */	virtual void BroadcastingHeartbeat(LPWSTR UserID, GUID PlayerSessionID, INT64 Heartbeat);
	/* 021 */	virtual void BroadcastingKill(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills);
	/* 022 */	virtual void BroadcastingMatchEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 023 */	virtual void BroadcastingMatchRoundEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 024 */	virtual void BroadcastingMatchRoundStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber);
	/* 025 */	virtual void BroadcastingMatchStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, LPWSTR PlaylistID);
	/* 026 */	virtual void BroadcastingMedal(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID);
	/* 027 */	virtual void BroadcastingPlayerJoined(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID);
	/* 028 */	virtual void BroadcastingPlayerLeft(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 029 */	virtual void BroadcastingPlayerSpawn(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 030 */	virtual void BroadcastingPlayerSwitchedTeams(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, LPWSTR WebColor);
	/* 031 */	virtual void BroadcastingScore(LPWSTR UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore);
	/* 032 */	virtual void BroadcastingStart(LPWSTR UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, LPWSTR PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime);
	/* 033 */	virtual void CampaignDifficulty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR CampaignDifficulty);
	/* 034 */	virtual void ChallengeCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 ChallengeID);
	/* 035 */	virtual void ClassicModeSwitched(LPWSTR UserID, GUID PlayerSessionID, INT32 MapID);
	/* 036 */	virtual void CleverGirl(LPWSTR UserID, GUID PlayerSessionID);
	/* 037 */	virtual void ClueClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 ClueID);
	/* 038 */	virtual void CoopMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID);
	/* 039 */	virtual void CoopSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID);
	/* 040 */	virtual void CompletionCount(LPWSTR UserID, GUID PlayerSessionID, INT32 Count);
	/* 041 */	virtual void Customization(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, LPWSTR ServiceID, LPWSTR ClanID, INT32 AvatarID, INT32 NameplateID);
	/* 042 */	virtual void DashboardContext(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DashboardContext);
	/* 043 */	virtual void Death(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot);
	/* 044 */	virtual void DollFound(LPWSTR UserID, GUID PlayerSessionID, INT32 DollID);
	/* 045 */	virtual void EliteWin(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade);
	/* 046 */	virtual void Emblem(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2);
	/* 047 */	virtual void EnemyDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot);
	/* 048 */	virtual void FriendsBestedOnHeroLeaderboard(LPWSTR UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows);
	/* 049 */	virtual void GameProgress(LPWSTR UserID, GUID PlayerSessionID, float CompletionPercent);
	/* 050 */	virtual void GameVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseGameCategory, LPWSTR GameVarName);
	/* 051 */	virtual void GrenadeStick(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID);
	/* 052 */	virtual void HelloNurse(LPWSTR UserID, GUID PlayerSessionID);
	/* 053 */	virtual void InGamePresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap);
	/* 054 */	virtual void ISeeYou(LPWSTR UserID, GUID PlayerSessionID);
	/* 055 */	virtual void Joinability(LPWSTR UserID, GUID PlayerSessionID, bool InGame);
	/* 056 */	virtual void Lobby(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR Lobby);
	/* 057 */	virtual void MainMenuPresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MainMenuPresence);
	/* 058 */	virtual void MapVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseMapID, LPWSTR MapVarName);
	/* 059 */	virtual void MatchmakingHopper(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MatchmakingHopper);
	/* 060 */	virtual void MediaUsage(LPWSTR AppSessionID, LPWSTR AppSessionStartDateTime, UINT32 UserIDType, LPWSTR UserID, LPWSTR SubscriptionTierType, LPWSTR SubscriptionTier, LPWSTR MediaType, LPWSTR ProviderID, LPWSTR ProviderMediaID, LPWSTR ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, LPWSTR AcquisitionType, LPWSTR AcquisitionContext, LPWSTR AcquisitionContextType, LPWSTR AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, LPWSTR MarketplaceLocation, LPWSTR ContentLocale, float TimeZoneOffset, UINT32 ScreenState);
	/* 061 */	virtual void MeldOfferPresented(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, LPWSTR Page, INT32 SourceTileIndex);
	/* 062 */	virtual void MeldOfferResponded(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome);
	/* 063 */	virtual void MeldPageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight);
	/* 064 */	virtual void MeldPageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content, LPWSTR FilterContext, INT32 FilterDirection);
	/* 065 */	virtual void MissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, LPWSTR PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete);
	/* 066 */	virtual void MortardomWraithsKilled(LPWSTR UserID, GUID PlayerSessionID);
	/* 067 */	virtual void MultiplayerGameEngine(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerGameEngine);
	/* 068 */	virtual void MultiplayerMap(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerMap);
	/* 069 */	virtual void MultiplayerRoundEnd(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID);
	/* 070 */	virtual void MultiplayerRoundStart(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID);
	/* 071 */	virtual void NappersCaught(LPWSTR UserID, GUID PlayerSessionID);
	/* 072 */	virtual void NewsStoryRead(LPWSTR UserID, GUID PlayerSessionID, LPWSTR StoryID);
	/* 073 */	virtual void ObjectiveEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID);
	/* 074 */	virtual void ObjectiveStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID);
	/* 075 */	virtual void PageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content);
	/* 076 */	virtual void PageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content);
	/* 077 */	virtual void PhantomHunter(LPWSTR UserID, GUID PlayerSessionID);
	/* 078 */	virtual void PigsCanFly(LPWSTR UserID, GUID PlayerSessionID);
	/* 079 */	virtual void PlayerCheckedInToday(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID);
	/* 080 */	virtual void PlayerDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ);
	/* 081 */	virtual void PlayerGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, LPWSTR CustomStat1ID, INT32 CustomStat1, LPWSTR CustomStat2ID, INT32 CustomStat2, LPWSTR CustomStat3ID, INT32 CustomStat3, LPWSTR CustomStat4ID, INT32 CustomStat4, GUID MatchID);
	/* 082 */	virtual void PlayerGameResultsDamageStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID);
	/* 083 */	virtual void PlayerGameResultsGriefingStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 084 */	virtual void PlayerGameResultsGriefingStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 085 */	virtual void PlayerGameResultsInterestStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay);
	/* 086 */	virtual void PlayerGameResultsMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount);
	/* 087 */	virtual void PlayerSessionEnd(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID);
	/* 088 */	virtual void PlayerSessionPause(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID);
	/* 089 */	virtual void PlayerSessionResume(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID);
	/* 090 */	virtual void PlayerSessionStart(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID);
	/* 091 */	virtual void PlayerSpawned(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ);
	/* 092 */	virtual void PlaylistCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, LPWSTR MissionStats, bool IsCoop);
	/* 093 */	virtual void PlaylistProgress(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS);
	/* 094 */	virtual void RankedStatsDNFInfo(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts);
	/* 095 */	virtual void RankedStatsOverride(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked);
	/* 096 */	virtual void RankedStatsPenalty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, INT32 NumPenaltiesApplied);
	/* 097 */	virtual void RankedStatsUpdate(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied);
	/* 098 */	virtual void RankedUpSpartanIv(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType);
	/* 099 */	virtual void RealtimeFlagCaptured(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade);
	/* 100 */	virtual void RealtimeMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount);
	/* 101 */	virtual void RealtimePilotedVehicle(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance);
	/* 102 */	virtual void RivalID(LPWSTR UserID, GUID PlayerSessionID, INT64 RivalID);
	/* 103 */	virtual void SectionEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID);
	/* 104 */	virtual void SectionStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID);
	/* 105 */	virtual void SectionStats(LPWSTR UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds);
	/* 106 */	virtual void SessionSizeUpdate(LPWSTR UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax);
	/* 107 */	virtual void SizeIsEverything(LPWSTR UserID, GUID PlayerSessionID);
	/* 108 */	virtual void SkeetShooter(LPWSTR UserID, GUID PlayerSessionID);
	/* 109 */	virtual void SkullClaimed(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID);
	/* 110 */	virtual void SoloMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed);
	/* 111 */	virtual void SoloSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID);
	/* 112 */	virtual void SpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop);
	/* 113 */	virtual void Supercombine(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID);
	/* 114 */	virtual void SurvivalSpace(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR SurvivalSpace);
	/* 115 */	virtual void TerminalFound(LPWSTR UserID, GUID PlayerSessionID, INT32 TerminalID);
	/* 116 */	virtual void TerminalID(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID);
	/* 117 */	virtual void TicketsEarned(LPWSTR UserID, GUID PlayerSessionID, INT32 TicketCount);
	/* 118 */	virtual void TitleCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID);
	/* 119 */	virtual void TitleLaunched(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID);
	/* 120 */	virtual void ValhallaSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID);
	/* 121 */	virtual void ViewOffer(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid);
	/* 122 */	virtual void VIPStatusEarned(LPWSTR UserID, GUID PlayerSessionID);
	/* 123 */	virtual void WhatAboutTanksDestroyed(LPWSTR UserID, GUID PlayerSessionID);
	/* 124 */	virtual void WonWarGame(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID);
	/* 125 */	virtual void ZanzibarSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID);
	/* 126 */	virtual void FirefightGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed);
	/* 127 */	virtual void EnemyDefeated_0(); // probably zombie defeated as these are in alphabetical order
	/* 128 */	virtual void CinematicStarted();
	/* 129 */	virtual void CinematicStopped();
	/* 130 */	virtual void Member130();
	/* 131 */	virtual void Member131();
	/* 132 */	virtual void Member132();
	/* 133 */	virtual void Member133();
	/* 134 */	virtual INT64 Member134(INT64);
	/* 135 */	virtual void Member135();
	/* 136 */	virtual GUID *__fastcall GetPlayerSessionID();
	/* 137 */	virtual void Member137();
	/* 138 */	virtual void CheckpointSaved();
	/* 139 */	virtual void CheckpointLoaded();

	struct __declspec(align(8)) UnknownType
	{
		INT64 qword0;
		INT64 *qword1;
		INT64 *qword2;
		INT32 dword0;
		INT32 dword1;
		INT64 qword4;
		INT64 *qword5;
		INT64 *qword6;
		INT32 dword2;
		INT32 dword3;
		INT32 dword4;
		INT32 dword5;
	};

	UINT8 unknown0[4] = {};
	GUID playerSessionID = {};
	UINT8 unknown14[220] = {};
};

IGameEvents::IGameEvents()
{
	HRESULT CoCreateGuidResult = CoCreateGuid(&playerSessionID);
#ifdef _DEBUG
	printf("IGameEvents();\n");
#endif
}

IGameEvents::~IGameEvents()
{
}

void IGameEvents::AchievementEarned(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 AchievementID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AchievementEarned(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, AchievementID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::AshesToAshes(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AshesToAshes(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Assist(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::AudioLogClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 AudioLogID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AudioLogClaimed(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, AudioLogID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Base(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Base(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Betrayal(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactControllerSettings(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactControllerSettings(\"%S\", %S, %s, \"%S\", %i, %i, %s)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, ControllerConfigurationID, LookInverted ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLink(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLink(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLinkRecieve(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLinkRecieve(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLinkSend(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLinkSend(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDualWield(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME DualWieldTimeStampUTC;
	::FileTimeToSystemTime(&DualWieldTimeStamp, &DualWieldTimeStampUTC);

	printf("IGameEvents::BIFactDualWield(\"%S\", %S, %s, \"%S\", %i, %i, %i, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, LeftWeaponID, RightWeaponID, DualWieldTimeStampUTC.wHour, DualWieldTimeStampUTC.wMinute, DualWieldTimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactGameSession(LPWSTR UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, LPWSTR HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, LPWSTR LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, LPWSTR HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactLoadout(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactLoadout(\"%S\", %S, %s, \"%S\", %i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, PrimaryWeaponID, SecondaryWeaponID, GrenadeID, ShieldID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactMatchmaking(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *PartyIDStr;
	StringFromCLSIDResult = StringFromCLSID(PartyID, &PartyIDStr);

	SYSTEMTIME LobbyEntryTimeStampUTC;
	::FileTimeToSystemTime(&LobbyEntryTimeStamp, &LobbyEntryTimeStampUTC);
	SYSTEMTIME JoinMatchTimeStampUTC;
	::FileTimeToSystemTime(&JoinMatchTimeStamp, &JoinMatchTimeStampUTC);

	printf("IGameEvents::BIFactMatchmaking(\"%S\", %S, %s, \"%S\", %02i:%02d:%02i, %s, %02i:%02d:%02i, %i, %lf, %i, %i, %S)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", LobbyID, LobbyEntryTimeStampUTC.wHour, LobbyEntryTimeStampUTC.wMinute, LobbyEntryTimeStampUTC.wSecond, JoinedMatch ? "true" : "false", JoinMatchTimeStampUTC.wHour, JoinMatchTimeStampUTC.wMinute, JoinMatchTimeStampUTC.wSecond, MatchmakingRank, MatchmakingRating, MatchmakingXP, PartySize, PartyIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(PartyIDStr);
}

void IGameEvents::BIFactMatchmakingDetails(LPWSTR UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, LPWSTR GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactMedia(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, LPWSTR MediaID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME MediaStartTimeStampUTC;
	::FileTimeToSystemTime(&MediaStartTimeStamp, &MediaStartTimeStampUTC);
	SYSTEMTIME MediaSkipTimeStampUTC;
	::FileTimeToSystemTime(&MediaSkipTimeStamp, &MediaSkipTimeStampUTC);

	printf("IGameEvents::BIFactMedia(\"%S\", %S, %s, \"%S\", %02i:%02d:%02i, %s, %02i:%02d:%02i, \"%S\")\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, MediaStartTimeStampUTC.wHour, MediaStartTimeStampUTC.wMinute, MediaStartTimeStampUTC.wSecond, WasSkipped ? "true" : "false", MediaSkipTimeStampUTC.wHour, MediaSkipTimeStampUTC.wMinute, MediaSkipTimeStampUTC.wSecond, MediaID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BirdOfPrey(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BirdOfPrey(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BitsAndPiecesDestroyed(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BitsAndPiecesDestroyed(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingAssist(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingAssist(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentAssists);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingDeath(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingHeartbeat(LPWSTR UserID, GUID PlayerSessionID, INT64 Heartbeat)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BroadcastingHeartbeat(\"%S\", %S, %lli)\n", UserID, PlayerSessionIDStr, Heartbeat);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingKill(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchEnd(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchRoundEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchRoundEnd(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchRoundStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchRoundStart(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, RoundNumber);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, LPWSTR PlaylistID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchStart(\"%S\", %S, %02i:%02d:%02i, %i, %i, \"%S\")\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MapVariantID, GameVariantID, PlaylistID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMedal(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMedal(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MedalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerJoined(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerJoined(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerLeft(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerLeft(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}
void IGameEvents::BroadcastingPlayerSpawn(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerSpawn(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerSwitchedTeams(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, LPWSTR WebColor)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	//printf("IGameEvents::BroadcastingPlayerSwitchedTeams(\"%S\", %S, %02d:%02d:%02d, %i, \"%S\")\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID, WebColor);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingScore(LPWSTR UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&Timestamp, &TimeStampUTC);

	//printf("IGameEvents::BroadcastingScore(\"%S\", %S, %i, %02i:%02d:%02i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, ControllerIndex, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentRoundScore, CurrentTotalScore, CurrentRoundTeamScore, CurrentTotalTeamScore);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingStart(LPWSTR UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, LPWSTR PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *MatchIDStr;
	StringFromCLSIDResult = StringFromCLSID(MatchID, &MatchIDStr);

	printf("IGameEvents::BroadcastingStart(\"%S\", %S, %u, %u, %u, \"%S\", %S, %s, %lli)\n", UserID, PlayerSessionIDStr, GameType, Map, TopPlayerRank, PlayerIDs, MatchIDStr, PlayerIsCaster ? "true" : "false", MatchStartTime);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(MatchIDStr);
}

void IGameEvents::CampaignDifficulty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR CampaignDifficulty)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CampaignDifficulty(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, CampaignDifficulty);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ChallengeCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 ChallengeID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ChallengeCompleted(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, ChallengeID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ClassicModeSwitched(LPWSTR UserID, GUID PlayerSessionID, INT32 MapID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ClassicModeSwitched(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, MapID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CleverGirl(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CleverGirl(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ClueClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 ClueID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ClueClaimed(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, ClueID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CoopMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CoopSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CoopSpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CompletionCount(LPWSTR UserID, GUID PlayerSessionID, INT32 Count)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CompletionCount(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, Count);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Customization(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, LPWSTR ServiceID, LPWSTR ClanID, INT32 AvatarID, INT32 NameplateID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Customization(\"%S\", %S, %i, %i, %i, %i, %i, \"%S\", \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2, ServiceID, ClanID, AvatarID, NameplateID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::DashboardContext(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DashboardContext)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::DashboardContext(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, DashboardContext);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Death(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::DollFound(LPWSTR UserID, GUID PlayerSessionID, INT32 DollID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::DollFound(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, DollID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EliteWin(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::EliteWin(\"%S\", %S, \"%S\", %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MatchMade ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Emblem(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Emblem(\"%S\", %S, %i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EnemyDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::FriendsBestedOnHeroLeaderboard(LPWSTR UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::FriendsBestedOnHeroLeaderboard(\"%S\", %S, %i, %i)\n", UserID, PlayerSessionIDStr, LeaderboardID, LeaderboardRows);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GameProgress(LPWSTR UserID, GUID PlayerSessionID, float CompletionPercent)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::GameProgress(\"%S\", %S, %f)\n", UserID, PlayerSessionIDStr, CompletionPercent);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GameVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseGameCategory, LPWSTR GameVarName)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::GameVarSaved(\"%S\", %S, \"%S\", %i, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, BaseGameCategory, GameVarName);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GrenadeStick(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::HelloNurse(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::HelloNurse(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::InGamePresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::InGamePresence(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitle, CampaignDifficulty, MultiplayerMap);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ISeeYou(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ISeeYou(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Joinability(LPWSTR UserID, GUID PlayerSessionID, bool InGame)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Joinability(\"%S\", %S, %s)\n", UserID, PlayerSessionIDStr, InGame ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Lobby(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR Lobby)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Lobby(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, Lobby);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MainMenuPresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MainMenuPresence)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MainMenuPresence(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, MainMenuPresence);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MapVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseMapID, LPWSTR MapVarName)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MapVarSaved(\"%S\", %S, \"%S\", %i, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, BaseMapID, MapVarName);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MatchmakingHopper(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MatchmakingHopper)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MatchmakingHopper(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MatchmakingHopper);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MediaUsage(LPWSTR AppSessionID, LPWSTR AppSessionStartDateTime, UINT32 UserIDType, LPWSTR UserID, LPWSTR SubscriptionTierType, LPWSTR SubscriptionTier, LPWSTR MediaType, LPWSTR ProviderID, LPWSTR ProviderMediaID, LPWSTR ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, LPWSTR AcquisitionType, LPWSTR AcquisitionContext, LPWSTR AcquisitionContextType, LPWSTR AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, LPWSTR MarketplaceLocation, LPWSTR ContentLocale, float TimeZoneOffset, UINT32 ScreenState)
{
	OLECHAR *BingIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(BingID, &BingIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, BingIDStr);

	::CoTaskMemFree(BingIDStr);
}

void IGameEvents::MeldOfferPresented(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, LPWSTR Page, INT32 SourceTileIndex)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::MeldOfferPresented(\"%S\", %S, %S, %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, Page, SourceTileIndex);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::MeldOfferResponded(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::MeldOfferResponded(\"%S\", %S, %S, %S, %i)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, UpsellOutcome);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::MeldPageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MeldPageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content, LPWSTR FilterContext, INT32 FilterDirection)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MeldPageView(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\", \"%S\", %i)\n", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content, FilterContext, FilterDirection);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, LPWSTR PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MortardomWraithsKilled(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MortardomWraithsKilled(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerGameEngine(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerGameEngine)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerGameEngine(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerGameEngine);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerMap(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerMap)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerMap(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerMap);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerRoundEnd(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID)
{
	OLECHAR *RoundIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
	OLECHAR *PlayerSessionIDStr;
	StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerRoundEnd(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i, %f, %i)\n", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID, TimeInSeconds, ExitStatusID);

	::CoTaskMemFree(RoundIDStr);
	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerRoundStart(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID)
{
	OLECHAR *RoundIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
	OLECHAR *PlayerSessionIDStr;
	StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerRoundStart(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i)\n", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID);

	::CoTaskMemFree(RoundIDStr);
	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::NappersCaught(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::NappersCaught(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::NewsStoryRead(LPWSTR UserID, GUID PlayerSessionID, LPWSTR StoryID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::NewsStoryRead(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, StoryID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ObjectiveEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ObjectiveEnd(\"%S\", %i, %S, \"%S\", %i, %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID, ExitStatusID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ObjectiveStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ObjectiveStart(\"%S\", %i, %S, \"%S\", %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PageAction(\"%S\", %S, %i, %i, \"%S\", \"%S\", \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, ActionTypeID, ActionInputMethodID, Page, TemplateID, DestinationPage, Content);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PageView(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PhantomHunter(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PhantomHunter(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PigsCanFly(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PigsCanFly(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerCheckedInToday(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerCheckedInToday(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, LPWSTR CustomStat1ID, INT32 CustomStat1, LPWSTR CustomStat2ID, INT32 CustomStat2, LPWSTR CustomStat3ID, INT32 CustomStat3, LPWSTR CustomStat4ID, INT32 CustomStat4, GUID MatchID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsDamageStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerGameResultsDamageStat(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", DamageReportingType, DamageStatisticType, DamageCount, GameCategoryID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsGriefingStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsGriefingStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsInterestStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerGameResultsMedal(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", MedalType, MedalCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionEnd(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionEnd(\"%S\", %S, \"%S\", %i, %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionPause(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionPause(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionResume(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionResume(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionStart(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionStart(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSpawned(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *RoundIDStr;
	StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);

	printf("IGameEvents::PlayerSpawned(\"%S\", %i, %S, \"%S\", %i, %i, %S, %i, %f, %f, %f)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, RoundIDStr, PlayerRoleID, LocationX, LocationY, LocationZ);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(RoundIDStr);
}

void IGameEvents::PlaylistCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, LPWSTR MissionStats, bool IsCoop)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlaylistCompleted(\"%S\", %S, \"%S\", %u, %llu, %llu, %i, \"%S\", %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, Score64, TimeMS, Penalties, MissionStats, IsCoop ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlaylistProgress(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlaylistProgress(\"%S\", %S, \"%S\", %i, %i, %llu, %s, %i, %s, %llu)\n", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, NumMapsCompleted, Score64, IsCoop ? "true" : "false", NumPlayers, ShouldPostTime ? "true" : "false", TotalPlayListTimeMS);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsDNFInfo(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsDNFInfo(\"%S\", %S, \"%S\", %lf, %i, %i, %lf)\n", UserID, PlayerSessionIDStr, HopperName, FinishesOverStarts, FinishesMinusStarts, FinishesPlusPenaltiesMinusStarts, FinishesPlusPenaltiesOverStarts);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsOverride(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsOverride(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s)\n", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsPenalty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, INT32 NumPenaltiesApplied)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsPenalty(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HopperName, NumPenaltiesApplied);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsUpdate(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsUpdate(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s, %s)\n", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false", PenaltyApplied ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedUpSpartanIv(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedUpSpartanIv(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SpartanIvRank, SpecialisationType);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimeFlagCaptured(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimeFlagCaptured(\"%S\", %S, \"%S\", %i, %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimeMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimeMedal(\"%S\", %S, \"%S\", %i, %i, %i, %s, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, GameCategoryID, GameMode, MatchMade ? "true" : "false", MedalType, MedalCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimePilotedVehicle(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimePilotedVehicle(\"%S\", %S, \"%S\", %i, %s, %i, %lli, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false", VehicleID, TimeMS, Distance);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RivalID(LPWSTR UserID, GUID PlayerSessionID, INT64 RivalID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RivalID(\"%S\", %S, %lli)\n", UserID, PlayerSessionIDStr, RivalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionEnd(\"%S\", %S, \"%S\", %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID, MissionID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionStart(\"%S\", %i, %S, \"%S\", %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, MissionID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionStats(LPWSTR UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionStats(\"%S\", %S, %i, %i, %i, %f, %f, %f)\n", UserID, PlayerSessionIDStr, MissionID, SectionID, SectionOrdinal, ScoreWithoutTimeBonus, ScoreWithTimeBonus, TimeInSeconds);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SessionSizeUpdate(LPWSTR UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SessionSizeUpdate(\"%S\", %S, %i, %i)\n", UserID, PlayerSessionIDStr, SessionSize, SessionSizeMax);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SizeIsEverything(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SizeIsEverything(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SkeetShooter(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SkeetShooter(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SkullClaimed(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SkullClaimed(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SoloMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SoloSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SoloSpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i, %i, %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MissionID, DifficultyID, IsCoop ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Supercombine(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SurvivalSpace(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR SurvivalSpace)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SurvivalSpace(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, SurvivalSpace);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TerminalFound(LPWSTR UserID, GUID PlayerSessionID, INT32 TerminalID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TerminalFound(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, TerminalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TerminalID(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TerminalID(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TicketsEarned(LPWSTR UserID, GUID PlayerSessionID, INT32 TicketCount)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TicketsEarned(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, TicketCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TitleCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TitleCompleted(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TitleLaunched(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TitleLaunched(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ValhallaSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ValhallaSign(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, SignID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ViewOffer(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::ValhallaSign(\"%S\", %S, %S, %S)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::VIPStatusEarned(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::VIPStatusEarned(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::WhatAboutTanksDestroyed(LPWSTR UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::WhatAboutTanksDestroyed(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::WonWarGame(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SurvivalSpace(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ZanzibarSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ZanzibarSign(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, SignID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::FirefightGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed)
{
	OLECHAR *PlayerSessionIDStr;
	HRESULT StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::FirefightGameResults(\"%S\", %S, \"%S\", %s, %llu, %u, %u, %u, %u, %u)\n", UserID, PlayerSessionIDStr, HaloTitleID, MatchMade ? "true" : "false", TimePlayedMS, Kills, MostKillsInARow, SetsCompleted, WavesCompleted, GeneratorsDestroyed);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EnemyDefeated_0()
{
}

void IGameEvents::CinematicStarted()
{
}

void IGameEvents::CinematicStopped()
{
}

void IGameEvents::Member130()
{
}

void IGameEvents::Member131()
{
}

void IGameEvents::Member132()
{
}

void IGameEvents::Member133()
{
}

INT64 IGameEvents::Member134(INT64)
{
	return 0;
}

void IGameEvents::Member135()
{
}

GUID *__fastcall IGameEvents::GetPlayerSessionID()
{
	return &playerSessionID;
}

void IGameEvents::Member137()
{
}

void IGameEvents::CheckpointSaved()
{
	printf("IGameEvents::CheckpointSaved()\n");
}

void IGameEvents::CheckpointLoaded()
{
	printf("IGameEvents::CheckpointLoaded()\n");
}