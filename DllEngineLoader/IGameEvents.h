#pragma once

// TODO: finish telemetry prints [	//printf("IGameEvents::(]

class IGameEvents
{
public:
	IGameEvents();
	~IGameEvents();

	/* 000 */	virtual void AchievementEarned(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 AchievementID);
	/* 001 */	virtual void AshesToAshes(wchar_t *UserID, GUID PlayerSessionID);
	/* 002 */	virtual void Assist(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade);
	/* 003 */	virtual void AudioLogClaimed(wchar_t *UserID, GUID PlayerSessionID, INT32 AudioLogID);
	/* 004 */	virtual void Base(wchar_t *UserID, GUID PlayerSessionID);
	/* 005 */	virtual void Betrayal(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade);
	/* 006 */	virtual void BIFactControllerSettings(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted);
	/* 007 */	virtual void BIFactDeepLink(wchar_t *UserID, GUID PlayerSessionID);
	/* 008 */	virtual void BIFactDeepLinkRecieve(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL);
	/* 009 */	virtual void BIFactDeepLinkSend(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL);
	/* 010 */	virtual void BIFactDualWield(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp);
	/* 011 */	virtual void BIFactGameSession(wchar_t *UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, wchar_t *HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, wchar_t *LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, wchar_t *HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides);
	/* 012 */	virtual void BIFactLoadout(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID);
	/* 013 */	virtual void BIFactMatchmaking(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID);
	/* 014 */	virtual void BIFactMatchmakingDetails(wchar_t *UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, wchar_t *GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated);
	/* 015 */	virtual void BIFactMedia(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, wchar_t *MediaID);
	/* 016 */	virtual void BirdOfPrey(wchar_t *UserID, GUID PlayerSessionID);
	/* 017 */	virtual void BitsAndPiecesDestroyed(wchar_t *UserID, GUID PlayerSessionID);
	/* 018 */	virtual void BroadcastingAssist(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists);
	/* 019 */	virtual void BroadcastingDeath(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, wchar_t *VictimXuid, UINT32 VictimTeamID, wchar_t *KillerXuid, UINT32 KillerTeamID, wchar_t *AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths);
	/* 020 */	virtual void BroadcastingHeartbeat(wchar_t *UserID, GUID PlayerSessionID, INT64 Heartbeat);
	/* 021 */	virtual void BroadcastingKill(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, wchar_t *VictimXuid, UINT32 VictimTeamID, wchar_t *KillerXuid, UINT32 KillerTeamID, wchar_t *AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills);
	/* 022 */	virtual void BroadcastingMatchEnd(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 023 */	virtual void BroadcastingMatchRoundEnd(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 024 */	virtual void BroadcastingMatchRoundStart(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber);
	/* 025 */	virtual void BroadcastingMatchStart(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, wchar_t *PlaylistID);
	/* 026 */	virtual void BroadcastingMedal(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID);
	/* 027 */	virtual void BroadcastingPlayerJoined(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID);
	/* 028 */	virtual void BroadcastingPlayerLeft(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 029 */	virtual void BroadcastingPlayerSpawn(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp);
	/* 030 */	virtual void BroadcastingPlayerSwitchedTeams(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, wchar_t *WebColor);
	/* 031 */	virtual void BroadcastingScore(wchar_t *UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore);
	/* 032 */	virtual void BroadcastingStart(wchar_t *UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, wchar_t *PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime);
	/* 033 */	virtual void CampaignDifficulty(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *CampaignDifficulty);
	/* 034 */	virtual void ChallengeCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 ChallengeID);
	/* 035 */	virtual void ClassicModeSwitched(wchar_t *UserID, GUID PlayerSessionID, INT32 MapID);
	/* 036 */	virtual void CleverGirl(wchar_t *UserID, GUID PlayerSessionID);
	/* 037 */	virtual void ClueClaimed(wchar_t *UserID, GUID PlayerSessionID, INT32 ClueID);
	/* 038 */	virtual void CoopMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID);
	/* 039 */	virtual void CoopSpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID);
	/* 040 */	virtual void CompletionCount(wchar_t *UserID, GUID PlayerSessionID, INT32 Count);
	/* 041 */	virtual void Customization(wchar_t *UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, wchar_t *ServiceID, wchar_t *ClanID, INT32 AvatarID, INT32 NameplateID);
	/* 042 */	virtual void DashboardContext(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DashboardContext);
	/* 043 */	virtual void Death(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot);
	/* 044 */	virtual void DollFound(wchar_t *UserID, GUID PlayerSessionID, INT32 DollID);
	/* 045 */	virtual void EliteWin(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, bool MatchMade);
	/* 046 */	virtual void Emblem(wchar_t *UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2);
	/* 047 */	virtual void EnemyDefeated(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot);
	/* 048 */	virtual void FriendsBestedOnHeroLeaderboard(wchar_t *UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows);
	/* 049 */	virtual void GameProgress(wchar_t *UserID, GUID PlayerSessionID, float CompletionPercent);
	/* 050 */	virtual void GameVarSaved(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 BaseGameCategory, wchar_t *GameVarName);
	/* 051 */	virtual void GrenadeStick(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID);
	/* 052 */	virtual void HelloNurse(wchar_t *UserID, GUID PlayerSessionID);
	/* 053 */	virtual void InGamePresence(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap);
	/* 054 */	virtual void ISeeYou(wchar_t *UserID, GUID PlayerSessionID);
	/* 055 */	virtual void Joinability(wchar_t *UserID, GUID PlayerSessionID, bool InGame);
	/* 056 */	virtual void Lobby(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *Lobby);
	/* 057 */	virtual void MainMenuPresence(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MainMenuPresence);
	/* 058 */	virtual void MapVarSaved(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 BaseMapID, wchar_t *MapVarName);
	/* 059 */	virtual void MatchmakingHopper(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MatchmakingHopper);
	/* 060 */	virtual void MediaUsage(wchar_t *AppSessionID, wchar_t *AppSessionStartDateTime, UINT32 UserIDType, wchar_t *UserID, wchar_t *SubscriptionTierType, wchar_t *SubscriptionTier, wchar_t *MediaType, wchar_t *ProviderID, wchar_t *ProviderMediaID, wchar_t *ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, wchar_t *AcquisitionType, wchar_t *AcquisitionContext, wchar_t *AcquisitionContextType, wchar_t *AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, wchar_t *MarketplaceLocation, wchar_t *ContentLocale, float TimeZoneOffset, UINT32 ScreenState);
	/* 061 */	virtual void MeldOfferPresented(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, wchar_t *Page, INT32 SourceTileIndex);
	/* 062 */	virtual void MeldOfferResponded(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome);
	/* 063 */	virtual void MeldPageAction(wchar_t *UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, wchar_t *Page, wchar_t *TemplateID, wchar_t *DestinationPage, wchar_t *Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight);
	/* 064 */	virtual void MeldPageView(wchar_t *UserID, GUID PlayerSessionID, wchar_t *Page, wchar_t *RefererPage, INT32 PageTypeID, wchar_t *PageTags, wchar_t *TemplateID, wchar_t *Content, wchar_t *FilterContext, INT32 FilterDirection);
	/* 065 */	virtual void MissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, wchar_t *PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete);
	/* 066 */	virtual void MortardomWraithsKilled(wchar_t *UserID, GUID PlayerSessionID);
	/* 067 */	virtual void MultiplayerGameEngine(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MultiplayerGameEngine);
	/* 068 */	virtual void MultiplayerMap(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MultiplayerMap);
	/* 069 */	virtual void MultiplayerRoundEnd(wchar_t *UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID);
	/* 070 */	virtual void MultiplayerRoundStart(wchar_t *UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID);
	/* 071 */	virtual void NappersCaught(wchar_t *UserID, GUID PlayerSessionID);
	/* 072 */	virtual void NewsStoryRead(wchar_t *UserID, GUID PlayerSessionID, wchar_t *StoryID);
	/* 073 */	virtual void ObjectiveEnd(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID);
	/* 074 */	virtual void ObjectiveStart(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID);
	/* 075 */	virtual void PageAction(wchar_t *UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, wchar_t *Page, wchar_t *TemplateID, wchar_t *DestinationPage, wchar_t *Content);
	/* 076 */	virtual void PageView(wchar_t *UserID, GUID PlayerSessionID, wchar_t *Page, wchar_t *RefererPage, INT32 PageTypeID, wchar_t *PageTags, wchar_t *TemplateID, wchar_t *Content);
	/* 077 */	virtual void PhantomHunter(wchar_t *UserID, GUID PlayerSessionID);
	/* 078 */	virtual void PigsCanFly(wchar_t *UserID, GUID PlayerSessionID);
	/* 079 */	virtual void PlayerCheckedInToday(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID);
	/* 080 */	virtual void PlayerDefeated(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ);
	/* 081 */	virtual void PlayerGameResults(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, wchar_t *CustomStat1ID, INT32 CustomStat1, wchar_t *CustomStat2ID, INT32 CustomStat2, wchar_t *CustomStat3ID, INT32 CustomStat3, wchar_t *CustomStat4ID, INT32 CustomStat4, GUID MatchID);
	/* 082 */	virtual void PlayerGameResultsDamageStat(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID);
	/* 083 */	virtual void PlayerGameResultsGriefingStat(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 084 */	virtual void PlayerGameResultsGriefingStats(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 085 */	virtual void PlayerGameResultsInterestStats(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay);
	/* 086 */	virtual void PlayerGameResultsMedal(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount);
	/* 087 */	virtual void PlayerSessionEnd(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID);
	/* 088 */	virtual void PlayerSessionPause(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID);
	/* 089 */	virtual void PlayerSessionResume(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID);
	/* 090 */	virtual void PlayerSessionStart(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID);
	/* 091 */	virtual void PlayerSpawned(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ);
	/* 092 */	virtual void PlaylistCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, wchar_t *MissionStats, bool IsCoop);
	/* 093 */	virtual void PlaylistProgress(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS);
	/* 094 */	virtual void RankedStatsDNFInfo(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts);
	/* 095 */	virtual void RankedStatsOverride(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked);
	/* 096 */	virtual void RankedStatsPenalty(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, INT32 NumPenaltiesApplied);
	/* 097 */	virtual void RankedStatsUpdate(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied);
	/* 098 */	virtual void RankedUpSpartanIv(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType);
	/* 099 */	virtual void RealtimeFlagCaptured(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, bool MatchMade);
	/* 100 */	virtual void RealtimeMedal(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount);
	/* 101 */	virtual void RealtimePilotedVehicle(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance);
	/* 102 */	virtual void RivalID(wchar_t *UserID, GUID PlayerSessionID, INT64 RivalID);
	/* 103 */	virtual void SectionEnd(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID);
	/* 104 */	virtual void SectionStart(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID);
	/* 105 */	virtual void SectionStats(wchar_t *UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds);
	/* 106 */	virtual void SessionSizeUpdate(wchar_t *UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax);
	/* 107 */	virtual void SizeIsEverything(wchar_t *UserID, GUID PlayerSessionID);
	/* 108 */	virtual void SkeetShooter(wchar_t *UserID, GUID PlayerSessionID);
	/* 109 */	virtual void SkullClaimed(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SkullID, INT32 DifficultyID);
	/* 110 */	virtual void SoloMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed);
	/* 111 */	virtual void SoloSpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID);
	/* 112 */	virtual void SpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop);
	/* 113 */	virtual void Supercombine(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID);
	/* 114 */	virtual void SurvivalSpace(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *SurvivalSpace);
	/* 115 */	virtual void TerminalFound(wchar_t *UserID, GUID PlayerSessionID, INT32 TerminalID);
	/* 116 */	virtual void TerminalID(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SkullID, INT32 DifficultyID);
	/* 117 */	virtual void TicketsEarned(wchar_t *UserID, GUID PlayerSessionID, INT32 TicketCount);
	/* 118 */	virtual void TitleCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID);
	/* 119 */	virtual void TitleLaunched(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID);
	/* 120 */	virtual void ValhallaSign(wchar_t *UserID, GUID PlayerSessionID, INT32 SignID);
	/* 121 */	virtual void ViewOffer(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid);
	/* 122 */	virtual void VIPStatusEarned(wchar_t *UserID, GUID PlayerSessionID);
	/* 123 */	virtual void WhatAboutTanksDestroyed(wchar_t *UserID, GUID PlayerSessionID);
	/* 124 */	virtual void WonWarGame(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID);
	/* 125 */	virtual void ZanzibarSign(wchar_t *UserID, GUID PlayerSessionID, INT32 SignID);
	/* 126 */	virtual void FirefightGameResults(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed);
	/* 127 */	virtual void EnemyDefeated_0(); // probably zombie defeated as these are in alphabetical order
	/* 128 */	virtual void Member128();
	/* 129 */	virtual void Member129();
	/* 130 */	virtual void Member130();
	/* 131 */	virtual void Member131();
	/* 132 */	virtual void Member132();
	/* 133 */	virtual void Member133();
	/* 134 */	virtual INT64 Member134(INT64);
	/* 135 */	virtual void Member135();
	/* 136 */	virtual GUID *__fastcall GetPlayerSessionID();
	/* 137 */	virtual void Member137();
	/* 138 */	virtual void CheckpointSaved();
	/* 139 */	virtual void Member139();

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
	auto CoCreateGuidResult = CoCreateGuid(&playerSessionID);
#ifdef _DEBUG
	printf("IGameEvents();\n");
#endif
}

IGameEvents::~IGameEvents()
{
}

void IGameEvents::AchievementEarned(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 AchievementID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AchievementEarned(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, AchievementID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::AshesToAshes(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AshesToAshes(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Assist(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::AudioLogClaimed(wchar_t *UserID, GUID PlayerSessionID, INT32 AudioLogID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::AudioLogClaimed(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, AudioLogID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Base(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Base(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Betrayal(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactControllerSettings(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactControllerSettings(\"%S\", %S, %s, \"%S\", %i, %i, %s)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, ControllerConfigurationID, LookInverted ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLink(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLink(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLinkRecieve(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLinkRecieve(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDeepLinkSend(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactDeepLinkSend(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactDualWield(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME DualWieldTimeStampUTC;
	::FileTimeToSystemTime(&DualWieldTimeStamp, &DualWieldTimeStampUTC);

	printf("IGameEvents::BIFactDualWield(\"%S\", %S, %s, \"%S\", %i, %i, %i, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, LeftWeaponID, RightWeaponID, DualWieldTimeStampUTC.wHour, DualWieldTimeStampUTC.wMinute, DualWieldTimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactGameSession(wchar_t *UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, wchar_t *HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, wchar_t *LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, wchar_t *HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactLoadout(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BIFactLoadout(\"%S\", %S, %s, \"%S\", %i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, PrimaryWeaponID, SecondaryWeaponID, GrenadeID, ShieldID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactMatchmaking(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
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

void IGameEvents::BIFactMatchmakingDetails(wchar_t *UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, wchar_t *GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BIFactMedia(wchar_t *UserID, GUID PlayerSessionID, bool IsGuest, wchar_t *HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, wchar_t *MediaID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME MediaStartTimeStampUTC;
	::FileTimeToSystemTime(&MediaStartTimeStamp, &MediaStartTimeStampUTC);
	SYSTEMTIME MediaSkipTimeStampUTC;
	::FileTimeToSystemTime(&MediaSkipTimeStamp, &MediaSkipTimeStampUTC);

	printf("IGameEvents::BIFactMedia(\"%S\", %S, %s, \"%S\", %02i:%02d:%02i, %s, %02i:%02d:%02i, \"%S\")\n", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, MediaStartTimeStampUTC.wHour, MediaStartTimeStampUTC.wMinute, MediaStartTimeStampUTC.wSecond, WasSkipped ? "true" : "false", MediaSkipTimeStampUTC.wHour, MediaSkipTimeStampUTC.wMinute, MediaSkipTimeStampUTC.wSecond, MediaID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BirdOfPrey(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BirdOfPrey(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BitsAndPiecesDestroyed(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BitsAndPiecesDestroyed(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingAssist(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingAssist(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentAssists);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingDeath(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, wchar_t *VictimXuid, UINT32 VictimTeamID, wchar_t *KillerXuid, UINT32 KillerTeamID, wchar_t *AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingHeartbeat(wchar_t *UserID, GUID PlayerSessionID, INT64 Heartbeat)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::BroadcastingHeartbeat(\"%S\", %S, %lli)\n", UserID, PlayerSessionIDStr, Heartbeat);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingKill(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, wchar_t *VictimXuid, UINT32 VictimTeamID, wchar_t *KillerXuid, UINT32 KillerTeamID, wchar_t *AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchEnd(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchEnd(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchRoundEnd(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchRoundEnd(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchRoundStart(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchRoundStart(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, RoundNumber);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMatchStart(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, wchar_t *PlaylistID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMatchStart(\"%S\", %S, %02i:%02d:%02i, %i, %i, \"%S\")\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MapVariantID, GameVariantID, PlaylistID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingMedal(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingMedal(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MedalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerJoined(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerJoined(\"%S\", %S, %02i:%02d:%02i, %i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerLeft(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerLeft(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}
void IGameEvents::BroadcastingPlayerSpawn(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	printf("IGameEvents::BroadcastingPlayerSpawn(\"%S\", %S, %02i:%02d:%02i)\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingPlayerSwitchedTeams(wchar_t *UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, wchar_t *WebColor)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

	//printf("IGameEvents::BroadcastingPlayerSwitchedTeams(\"%S\", %S, %02d:%02d:%02d, %i, \"%S\")\n", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID, WebColor);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingScore(wchar_t *UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	SYSTEMTIME TimeStampUTC;
	::FileTimeToSystemTime(&Timestamp, &TimeStampUTC);

	//printf("IGameEvents::BroadcastingScore(\"%S\", %S, %i, %02i:%02d:%02i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, ControllerIndex, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentRoundScore, CurrentTotalScore, CurrentRoundTeamScore, CurrentTotalTeamScore);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::BroadcastingStart(wchar_t *UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, wchar_t *PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *MatchIDStr;
	StringFromCLSIDResult = StringFromCLSID(MatchID, &MatchIDStr);

	printf("IGameEvents::BroadcastingStart(\"%S\", %S, %u, %u, %u, \"%S\", %S, %s, %lli)\n", UserID, PlayerSessionIDStr, GameType, Map, TopPlayerRank, PlayerIDs, MatchIDStr, PlayerIsCaster ? "true" : "false", MatchStartTime);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(MatchIDStr);
}

void IGameEvents::CampaignDifficulty(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *CampaignDifficulty)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CampaignDifficulty(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, CampaignDifficulty);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ChallengeCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 ChallengeID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ChallengeCompleted(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, ChallengeID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ClassicModeSwitched(wchar_t *UserID, GUID PlayerSessionID, INT32 MapID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ClassicModeSwitched(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, MapID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CleverGirl(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CleverGirl(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ClueClaimed(wchar_t *UserID, GUID PlayerSessionID, INT32 ClueID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ClueClaimed(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, ClueID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CoopMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CoopSpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CoopSpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::CompletionCount(wchar_t *UserID, GUID PlayerSessionID, INT32 Count)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::CompletionCount(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, Count);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Customization(wchar_t *UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, wchar_t *ServiceID, wchar_t *ClanID, INT32 AvatarID, INT32 NameplateID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Customization(\"%S\", %S, %i, %i, %i, %i, %i, \"%S\", \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2, ServiceID, ClanID, AvatarID, NameplateID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::DashboardContext(wchar_t *UserID, GUID PlayerSessionID, wchar_t *DashboardContext)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::DashboardContext(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, DashboardContext);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Death(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::DollFound(wchar_t *UserID, GUID PlayerSessionID, INT32 DollID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::DollFound(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, DollID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EliteWin(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::EliteWin(\"%S\", %S, \"%S\", %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MatchMade ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Emblem(wchar_t *UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Emblem(\"%S\", %S, %i, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EnemyDefeated(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, wchar_t *HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::FriendsBestedOnHeroLeaderboard(wchar_t *UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::FriendsBestedOnHeroLeaderboard(\"%S\", %S, %i, %i)\n", UserID, PlayerSessionIDStr, LeaderboardID, LeaderboardRows);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GameProgress(wchar_t *UserID, GUID PlayerSessionID, float CompletionPercent)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::GameProgress(\"%S\", %S, %f)\n", UserID, PlayerSessionIDStr, CompletionPercent);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GameVarSaved(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 BaseGameCategory, wchar_t *GameVarName)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::GameVarSaved(\"%S\", %S, \"%S\", %i, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, BaseGameCategory, GameVarName);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::GrenadeStick(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::HelloNurse(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::HelloNurse(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::InGamePresence(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::InGamePresence(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitle, CampaignDifficulty, MultiplayerMap);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ISeeYou(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ISeeYou(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Joinability(wchar_t *UserID, GUID PlayerSessionID, bool InGame)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Joinability(\"%S\", %S, %s)\n", UserID, PlayerSessionIDStr, InGame ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Lobby(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *Lobby)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::Lobby(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, Lobby);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MainMenuPresence(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MainMenuPresence)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MainMenuPresence(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, MainMenuPresence);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MapVarSaved(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 BaseMapID, wchar_t *MapVarName)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MapVarSaved(\"%S\", %S, \"%S\", %i, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, BaseMapID, MapVarName);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MatchmakingHopper(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MatchmakingHopper)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MatchmakingHopper(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MatchmakingHopper);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MediaUsage(wchar_t *AppSessionID, wchar_t *AppSessionStartDateTime, UINT32 UserIDType, wchar_t *UserID, wchar_t *SubscriptionTierType, wchar_t *SubscriptionTier, wchar_t *MediaType, wchar_t *ProviderID, wchar_t *ProviderMediaID, wchar_t *ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, wchar_t *AcquisitionType, wchar_t *AcquisitionContext, wchar_t *AcquisitionContextType, wchar_t *AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, wchar_t *MarketplaceLocation, wchar_t *ContentLocale, float TimeZoneOffset, UINT32 ScreenState)
{
	OLECHAR *BingIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(BingID, &BingIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, BingIDStr);

	::CoTaskMemFree(BingIDStr);
}

void IGameEvents::MeldOfferPresented(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, wchar_t *Page, INT32 SourceTileIndex)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::MeldOfferPresented(\"%S\", %S, %S, %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, Page, SourceTileIndex);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::MeldOfferResponded(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::MeldOfferResponded(\"%S\", %S, %S, %S, %i)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, UpsellOutcome);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::MeldPageAction(wchar_t *UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, wchar_t *Page, wchar_t *TemplateID, wchar_t *DestinationPage, wchar_t *Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MeldPageView(wchar_t *UserID, GUID PlayerSessionID, wchar_t *Page, wchar_t *RefererPage, INT32 PageTypeID, wchar_t *PageTags, wchar_t *TemplateID, wchar_t *Content, wchar_t *FilterContext, INT32 FilterDirection)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MeldPageView(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\", \"%S\", %i)\n", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content, FilterContext, FilterDirection);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, wchar_t *PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MortardomWraithsKilled(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MortardomWraithsKilled(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerGameEngine(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MultiplayerGameEngine)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerGameEngine(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerGameEngine);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerMap(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *MultiplayerMap)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerMap(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerMap);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerRoundEnd(wchar_t *UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID)
{
	OLECHAR *RoundIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
	OLECHAR *PlayerSessionIDStr;
	StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerRoundEnd(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i, %f, %i)\n", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID, TimeInSeconds, ExitStatusID);

	::CoTaskMemFree(RoundIDStr);
	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::MultiplayerRoundStart(wchar_t *UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID)
{
	OLECHAR *RoundIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
	OLECHAR *PlayerSessionIDStr;
	StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::MultiplayerRoundStart(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i)\n", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID);

	::CoTaskMemFree(RoundIDStr);
	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::NappersCaught(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::NappersCaught(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::NewsStoryRead(wchar_t *UserID, GUID PlayerSessionID, wchar_t *StoryID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::NewsStoryRead(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, StoryID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ObjectiveEnd(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ObjectiveEnd(\"%S\", %i, %S, \"%S\", %i, %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID, ExitStatusID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ObjectiveStart(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ObjectiveStart(\"%S\", %i, %S, \"%S\", %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PageAction(wchar_t *UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, wchar_t *Page, wchar_t *TemplateID, wchar_t *DestinationPage, wchar_t *Content)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PageAction(\"%S\", %S, %i, %i, \"%S\", \"%S\", \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, ActionTypeID, ActionInputMethodID, Page, TemplateID, DestinationPage, Content);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PageView(wchar_t *UserID, GUID PlayerSessionID, wchar_t *Page, wchar_t *RefererPage, INT32 PageTypeID, wchar_t *PageTags, wchar_t *TemplateID, wchar_t *Content)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PageView(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PhantomHunter(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PhantomHunter(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PigsCanFly(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PigsCanFly(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerCheckedInToday(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerCheckedInToday(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerDefeated(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResults(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, wchar_t *CustomStat1ID, INT32 CustomStat1, wchar_t *CustomStat2ID, INT32 CustomStat2, wchar_t *CustomStat3ID, INT32 CustomStat3, wchar_t *CustomStat4ID, INT32 CustomStat4, GUID MatchID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsDamageStat(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerGameResultsDamageStat(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", DamageReportingType, DamageStatisticType, DamageCount, GameCategoryID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsGriefingStat(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsGriefingStats(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsInterestStats(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerGameResultsMedal(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerGameResultsMedal(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", MedalType, MedalCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionEnd(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionEnd(\"%S\", %S, \"%S\", %i, %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionPause(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionPause(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionResume(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionResume(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSessionStart(wchar_t *UserID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlayerSessionStart(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlayerSpawned(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *RoundIDStr;
	StringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);

	printf("IGameEvents::PlayerSpawned(\"%S\", %i, %S, \"%S\", %i, %i, %S, %i, %f, %f, %f)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, RoundIDStr, PlayerRoleID, LocationX, LocationY, LocationZ);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(RoundIDStr);
}

void IGameEvents::PlaylistCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, wchar_t *MissionStats, bool IsCoop)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlaylistCompleted(\"%S\", %S, \"%S\", %u, %llu, %llu, %i, \"%S\", %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, Score64, TimeMS, Penalties, MissionStats, IsCoop ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::PlaylistProgress(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::PlaylistProgress(\"%S\", %S, \"%S\", %i, %i, %llu, %s, %i, %s, %llu)\n", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, NumMapsCompleted, Score64, IsCoop ? "true" : "false", NumPlayers, ShouldPostTime ? "true" : "false", TotalPlayListTimeMS);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsDNFInfo(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsDNFInfo(\"%S\", %S, \"%S\", %lf, %i, %i, %lf)\n", UserID, PlayerSessionIDStr, HopperName, FinishesOverStarts, FinishesMinusStarts, FinishesPlusPenaltiesMinusStarts, FinishesPlusPenaltiesOverStarts);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsOverride(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsOverride(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s)\n", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsPenalty(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, INT32 NumPenaltiesApplied)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsPenalty(\"%S\", %S, \"%S\", %i)\n", UserID, PlayerSessionIDStr, HopperName, NumPenaltiesApplied);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedStatsUpdate(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedStatsUpdate(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s, %s)\n", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false", PenaltyApplied ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RankedUpSpartanIv(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RankedUpSpartanIv(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SpartanIvRank, SpecialisationType);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimeFlagCaptured(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, bool MatchMade)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimeFlagCaptured(\"%S\", %S, \"%S\", %i, %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimeMedal(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimeMedal(\"%S\", %S, \"%S\", %i, %i, %i, %s, %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, GameCategoryID, GameMode, MatchMade ? "true" : "false", MedalType, MedalCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RealtimePilotedVehicle(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RealtimePilotedVehicle(\"%S\", %S, \"%S\", %i, %s, %i, %lli, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false", VehicleID, TimeMS, Distance);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::RivalID(wchar_t *UserID, GUID PlayerSessionID, INT64 RivalID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::RivalID(\"%S\", %S, %lli)\n", UserID, PlayerSessionIDStr, RivalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionEnd(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionEnd(\"%S\", %S, \"%S\", %i, %i, %i, %i)\n", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID, MissionID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionStart(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionStart(\"%S\", %i, %S, \"%S\", %i, %i, %i)\n", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, MissionID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SectionStats(wchar_t *UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SectionStats(\"%S\", %S, %i, %i, %i, %f, %f, %f)\n", UserID, PlayerSessionIDStr, MissionID, SectionID, SectionOrdinal, ScoreWithoutTimeBonus, ScoreWithTimeBonus, TimeInSeconds);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SessionSizeUpdate(wchar_t *UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SessionSizeUpdate(\"%S\", %S, %i, %i)\n", UserID, PlayerSessionIDStr, SessionSize, SessionSizeMax);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SizeIsEverything(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SizeIsEverything(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SkeetShooter(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SkeetShooter(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SkullClaimed(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SkullClaimed(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SoloMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SoloSpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SoloSpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SpartanOpsMissionCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SpartanOpsMissionCompleted(\"%S\", %S, \"%S\", %i, %i, %i, %s)\n", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MissionID, DifficultyID, IsCoop ? "true" : "false");

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::Supercombine(wchar_t *UserID, INT32 SectionID, GUID PlayerSessionID, wchar_t *MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::SurvivalSpace(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, wchar_t *SurvivalSpace)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SurvivalSpace(\"%S\", %S, \"%S\", \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID, SurvivalSpace);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TerminalFound(wchar_t *UserID, GUID PlayerSessionID, INT32 TerminalID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TerminalFound(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, TerminalID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TerminalID(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TerminalID(\"%S\", %S, \"%S\", %i, %i)\n", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TicketsEarned(wchar_t *UserID, GUID PlayerSessionID, INT32 TicketCount)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TicketsEarned(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, TicketCount);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TitleCompleted(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TitleCompleted(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::TitleLaunched(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::TitleLaunched(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ValhallaSign(wchar_t *UserID, GUID PlayerSessionID, INT32 SignID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ValhallaSign(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, SignID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ViewOffer(wchar_t *UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
	OLECHAR *OfferGuidStr;
	StringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
	OLECHAR *ProductGuidStr;
	StringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

	printf("IGameEvents::ValhallaSign(\"%S\", %S, %S, %S)\n", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr);

	::CoTaskMemFree(PlayerSessionIDStr);
	::CoTaskMemFree(OfferGuidStr);
	::CoTaskMemFree(ProductGuidStr);
}

void IGameEvents::VIPStatusEarned(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::VIPStatusEarned(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::WhatAboutTanksDestroyed(wchar_t *UserID, GUID PlayerSessionID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::WhatAboutTanksDestroyed(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::WonWarGame(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::SurvivalSpace(\"%S\", %S, \"%S\")\n", UserID, PlayerSessionIDStr, HaloTitleID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::ZanzibarSign(wchar_t *UserID, GUID PlayerSessionID, INT32 SignID)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	printf("IGameEvents::ZanzibarSign(\"%S\", %S, %i)\n", UserID, PlayerSessionIDStr, SignID);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::FirefightGameResults(wchar_t *UserID, GUID PlayerSessionID, wchar_t *HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed)
{
	OLECHAR *PlayerSessionIDStr;
	auto StringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

	//printf("IGameEvents::(\"%S\", %S)\n", UserID, PlayerSessionIDStr);

	::CoTaskMemFree(PlayerSessionIDStr);
}

void IGameEvents::EnemyDefeated_0()
{
}

void IGameEvents::Member128()
{
}

void IGameEvents::Member129()
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
}

void IGameEvents::Member139()
{
}