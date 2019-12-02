#pragma once

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;

class IGameEvents
{
public:

	static bool g_logGameEventMessages;


	/* 0   */	virtual void AchievementEarned(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 AchievementId);
	/* 1   */	virtual void AshesToAshes(wchar_t *UserId, GUID PlayerSessionId);
	/* 2   */	virtual void Assist(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade);
	/* 3   */	virtual void AudioLogClaimed(wchar_t *UserId, GUID PlayerSessionId, int32 AudioLogId);
	/* 4   */	virtual void Base(wchar_t *UserId, GUID PlayerSessionId);
	/* 5   */	virtual void Betrayal(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade);
	/* 6   */	virtual void BIFactControllerSettings(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 ControllerConfigurationID, bool LookInverted);
	/* 7   */	virtual void BIFactDeepLink(wchar_t *UserId, GUID PlayerSessionId);
	/* 8   */	virtual void BIFactDeepLinkRecieve(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL);
	/* 9   */	virtual void BIFactDeepLinkSend(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL);
	/* 10  */	virtual void BIFactDualWield(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 LeftWeaponID, int32 RightWeaponID, uint64 DualWieldTimeStamp);
	/* 11  */	virtual void BIFactGameSession(wchar_t *UserId, GUID PlayerSessionId, uint64 SessionStartTimeStamp, uint64 SessionEndTimeStamp, wchar_t *HaloTitleID, uint64 SubTitleStartTimeStamp, uint64 SubTitleEndTimeStamp, int32 GameCategoryID, wchar_t *LocaleID, int32 MapID, int32 ArmorID, uint64 SkullsUsed, wchar_t *HopperID, int32 PlayerCount, bool Matchmade, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, bool Won, uint64 Score, uint64 TeamScore, int32 Standing, bool FirstPlace, int32 Kills, int32 Deaths, int32 Assists, int32 Betrayals, int32 Suicides);
	/* 12  */	virtual void BIFactLoadout(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 PrimaryWeaponID, int32 SecondaryWeaponID, int32 GrenadeID, int32 ShieldID);
	/* 13  */	virtual void BIFactMatchmaking(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *LobbyID, uint64 LobbyEntryTimeStamp, bool JoinedMatch, uint64 JoinMatchTimeStamp, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, int32 PartySize, GUID PartyID);
	/* 14  */	virtual void BIFactMatchmakingDetails(wchar_t *UserId, GUID PlayerSessionId, int32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, uint64 LobbyEntryTimeStamp, uint64 LobbyExitTimeStamp, int32 ExitReason, wchar_t *GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, int32 NumPlayers, int32 NumPreserveSessionTicketsCreated);
	/* 15  */	virtual void BIFactMedia(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, uint64 MediaStartTimeStamp, bool WasSkipped, uint64 MediaSkipTimeStamp, wchar_t *MediaID);
	/* 16  */	virtual void BirdOfPrey(wchar_t *UserId, GUID PlayerSessionId);
	/* 17  */	virtual void BitsAndPiecesDestroyed(wchar_t *UserId, GUID PlayerSessionId);
	/* 18  */	virtual void BroadcastingAssist(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 CurrentAssists);
	/* 19  */	virtual void BroadcastingDeath(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t *VictimXuid, uint32 VictimTeamId, wchar_t *KillerXuid, uint32 KillerTeamId, wchar_t *AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentDeaths);
	/* 20  */	virtual void BroadcastingHeartbeat(wchar_t *UserId, GUID PlayerSessionId, int64 Heartbeat);
	/* 21  */	virtual void BroadcastingKill(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t *VictimXuid, uint32 VictimTeamId, wchar_t *KillerXuid, uint32 KillerTeamId, wchar_t *AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentKills);
	/* 22  */	virtual void BroadcastingMatchEnd(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp);
	/* 23  */	virtual void BroadcastingMatchRoundEnd(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp);
	/* 24  */	virtual void BroadcastingMatchRoundStart(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 RoundNumber);
	/* 25  */	virtual void BroadcastingMatchStart(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MapVariantID, int32 GameVariantID, wchar_t *PlaylistID);
	/* 26  */	virtual void BroadcastingMedal(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MedalId);
	/* 27  */	virtual void BroadcastingPlayerJoined(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId);
	/* 28  */	virtual void BroadcastingPlayerLeft(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp);
	/* 29  */	virtual void BroadcastingPlayerSpawn(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp);
	/* 30  */	virtual void BroadcastingPlayerSwitchedTeams(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId, wchar_t *WebColor);
	/* 31  */	virtual void BroadcastingScore(wchar_t *UserId, GUID PlayerSessionId, int32 ControllerIndex, int64 Timestamp, int32 CurrentRoundScore, int32 CurrentTotalScore, int32 CurrentRoundTeamScore, int32 CurrentTotalTeamScore);
	/* 32  */	virtual void BroadcastingStart(wchar_t *UserId, GUID PlayerSessionId, uint32 GameType, uint32 Map, uint32 TopPlayerRank, wchar_t *PlayerIDs, GUID MatchID, bool PlayerIsCaster, int64 MatchStartTime);
	/* 33  */	virtual void CampaignDifficulty(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *CampaignDifficulty);
	/* 34  */	virtual void ChallengeCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 ChallengeId);
	/* 35  */	virtual void ClassicModeSwitched(wchar_t *UserId, GUID PlayerSessionId, int32 MapId);
	/* 36  */	virtual void CleverGirl(wchar_t *UserId, GUID PlayerSessionId);
	/* 37  */	virtual void ClueClaimed(wchar_t *UserId, GUID PlayerSessionId, int32 ClueId);
	/* 38  */	virtual void CoopMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MissionId, int32 MapId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, int32 DifficultyId);
	/* 39  */	virtual void CoopSpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId);
	/* 40  */	virtual void CompletionCount(wchar_t *UserId, GUID PlayerSessionId, int32 Count);
	/* 41  */	virtual void Customization(wchar_t *UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2, wchar_t *ServiceId, wchar_t *ClanId, int32 AvatarId, int32 NameplateId);
	/* 42  */	virtual void DashboardContext(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DashboardContext);
	/* 43  */	virtual void Death(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot);
	/* 44  */	virtual void DollFound(wchar_t *UserId, GUID PlayerSessionId, int32 DollId);
	/* 45  */	virtual void EliteWin(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, bool MatchMade);
	/* 46  */	virtual void Emblem(wchar_t *UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2);
	/* 47  */	virtual void EnemyDefeated(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot);
	/* 48  */	virtual void FriendsBestedOnHeroLeaderboard(wchar_t *UserId, GUID PlayerSessionId, int32 LeaderboardId, int32 LeaderboardRows);
	/* 49  */	virtual void GameProgress(wchar_t *UserId, GUID PlayerSessionId, float CompletionPercent);
	/* 50  */	virtual void GameVarSaved(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 BaseGameCategory, wchar_t *GameVarName);
	/* 51  */	virtual void GrenadeStick(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId);
	/* 52  */	virtual void HelloNurse(wchar_t *UserId, GUID PlayerSessionId);
	/* 53  */	virtual void InGamePresence(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitle, int32 CampaignDifficulty, int32 MultiplayerMap);
	/* 54  */	virtual void ISeeYou(wchar_t *UserId, GUID PlayerSessionId);
	/* 55  */	virtual void Joinability(wchar_t *UserId, GUID PlayerSessionId, bool InGame);
	/* 56  */	virtual void Lobby(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *Lobby);
	/* 57  */	virtual void MainMenuPresence(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MainMenuPresence);
	/* 58  */	virtual void MapVarSaved(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 BaseMapId, wchar_t *MapVarName);
	/* 59  */	virtual void MatchmakingHopper(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MatchmakingHopper);
	/* 60  */	virtual void MediaUsage(wchar_t *AppSessionId, wchar_t *AppSessionStartDateTime, uint32 UserIdType, wchar_t *UserId, wchar_t *SubscriptionTierType, wchar_t *SubscriptionTier, wchar_t *MediaType, wchar_t *ProviderId, wchar_t *ProviderMediaId, wchar_t *ProviderMediaInstanceId, GUID BingId, uint64 MediaLengthMs, uint32 MediaControlAction, float PlaybackSpeed, uint64 MediaPositionMs, uint64 PlaybackDurationMs, wchar_t *AcquisitionType, wchar_t *AcquisitionContext, wchar_t *AcquisitionContextType, wchar_t *AcquisitionContextId, int32 PlaybackIsStream, int32 PlaybackIsTethered, wchar_t *MarketplaceLocation, wchar_t *ContentLocale, float TimeZoneOffset, uint32 ScreenState);
	/* 61  */	virtual void MeldOfferPresented(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, wchar_t *Page, int32 SourceTileIndex);
	/* 62  */	virtual void MeldOfferResponded(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, int32 UpsellOutcome);
	/* 63  */	virtual void MeldPageAction(wchar_t *UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t *Page, wchar_t *TemplateId, wchar_t *DestinationPage, wchar_t *Content, int32 SourceTileIndex, int32 SourceTileX, int32 SourceTileY, int32 SourceTileWidth, int32 SourceTileHeight);
	/* 64  */	virtual void MeldPageView(wchar_t *UserId, GUID PlayerSessionId, wchar_t *Page, wchar_t *RefererPage, int32 PageTypeId, wchar_t *PageTags, wchar_t *TemplateId, wchar_t *Content, wchar_t *FilterContext, int32 FilterDirection);
	/* 65  */	virtual void MissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 GameCategoryId, bool Coop, uint64 TimePlayedMS, uint64 DatePlayedUTC, int32 DifficultyId, uint64 MissionScore64, uint64 SkullUsedFlags, int32 NumPlayers, wchar_t *PlayerSectionStats, int32 Kills, float Multiplier, int32 Penalties, float SkullMultiplier, int32 TotalSoloMissionsComplete, int32 TotalCoopMissionsComplete);
	/* 66  */	virtual void MortardomWraithsKilled(wchar_t *UserId, GUID PlayerSessionId);
	/* 67  */	virtual void MultiplayerGameEngine(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MultiplayerGameEngine);
	/* 68  */	virtual void MultiplayerMap(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MultiplayerMap);
	/* 69  */	virtual void MultiplayerRoundEnd(wchar_t *UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId, float TimeInSeconds, int32 ExitStatusId);
	/* 70  */	virtual void MultiplayerRoundStart(wchar_t *UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId);
	/* 71  */	virtual void NappersCaught(wchar_t *UserId, GUID PlayerSessionId);
	/* 72  */	virtual void NewsStoryRead(wchar_t *UserId, GUID PlayerSessionId, wchar_t *StoryId);
	/* 73  */	virtual void ObjectiveEnd(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId, int32 ExitStatusId);
	/* 74  */	virtual void ObjectiveStart(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId);
	/* 75  */	virtual void PageAction(wchar_t *UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t *Page, wchar_t *TemplateId, wchar_t *DestinationPage, wchar_t *Content);
	/* 76  */	virtual void PageView(wchar_t *UserId, GUID PlayerSessionId, wchar_t *Page, wchar_t *RefererPage, int32 PageTypeId, wchar_t *PageTags, wchar_t *TemplateId, wchar_t *Content);
	/* 77  */	virtual void PhantomHunter(wchar_t *UserId, GUID PlayerSessionId);
	/* 78  */	virtual void PigsCanFly(wchar_t *UserId, GUID PlayerSessionId);
	/* 79  */	virtual void PlayerCheckedInToday(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId);
	/* 80  */	virtual void PlayerDefeated(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 EnemyWeaponId, float LocationX, float LocationY, float LocationZ);
	/* 81  */	virtual void PlayerGameResults(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 GameIndexByCategory, int32 GameIndexByTitle, int32 GameIndexByTitleCategory, int32 MapId, int32 GameCategoryId, bool MatchMade, bool Won, uint64 TimePlayedMS, uint64 DatePlayedUTC, uint64 Score64, int32 Standing, bool FirstPlace, int32 MedalCount, int32 Kills, int32 Deaths, int32 Assists, int32 HeadShots, int32 MostKillsInARow, wchar_t *CustomStat1ID, int32 CustomStat1, wchar_t *CustomStat2ID, int32 CustomStat2, wchar_t *CustomStat3ID, int32 CustomStat3, wchar_t *CustomStat4ID, int32 CustomStat4, GUID MatchId);
	/* 82  */	virtual void PlayerGameResultsDamageStat(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 DamageReportingType, int32 DamageStatisticType, int32 DamageCount, int32 GameCategoryId);
	/* 83  */	virtual void PlayerGameResultsGriefingStat(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 84  */	virtual void PlayerGameResultsGriefingStats(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty);
	/* 85  */	virtual void PlayerGameResultsInterestStats(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameCategoryId, int32 GameIndex, int32 MapId, bool MatchMade, int32 OrdnanceDrops, int32 OrdnanceStrikes, uint64 TimeMSDriven, int32 UnitsDriven, uint64 TimeMSPiloted, int32 UnitsPiloted, uint64 TimeMSPassenger, int32 UnitsMovedPassenger, uint64 TimeMSOnFoot, int32 UnitsMovedOnFoot, int32 DriverAssists, int32 ArmorAbilityUseJetpack, int32 ArmorAbilityUseHologram, int32 ArmorAbilityUseReflectiveShield, int32 ArmorAbilityUseActiveCamo, int32 ArmorAbilityUseThrusterPack, int32 ArmorAbilityUseAutoTurret, int32 ArmorAbilityUseXRay);
	/* 86  */	virtual void PlayerGameResultsMedal(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 MedalType, int32 MedalCount);
	/* 87  */	virtual void PlayerSessionEnd(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId);
	/* 88  */	virtual void PlayerSessionPause(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId);
	/* 89  */	virtual void PlayerSessionResume(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId);
	/* 90  */	virtual void PlayerSessionStart(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId);
	/* 91  */	virtual void PlayerSpawned(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, float LocationX, float LocationY, float LocationZ);
	/* 92  */	virtual void PlaylistCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, uint32 PlaylistId, uint64 Score64, uint64 TimeMS, int32 Penalties, wchar_t *MissionStats, bool IsCoop);
	/* 93  */	virtual void PlaylistProgress(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 PlaylistId, int32 NumMapsCompleted, uint64 Score64, bool IsCoop, int32 NumPlayers, bool ShouldPostTime, uint64 TotalPlayListTimeMS);
	/* 94  */	virtual void RankedStatsDNFInfo(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double FinishesOverStarts, int32 FinishesMinusStarts, int32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts);
	/* 95  */	virtual void RankedStatsOverride(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked);
	/* 96  */	virtual void RankedStatsPenalty(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, int32 NumPenaltiesApplied);
	/* 97  */	virtual void RankedStatsUpdate(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked, bool PenaltyApplied);
	/* 98  */	virtual void RankedUpSpartanIv(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SpartanIvRank, int32 SpecialisationType);
	/* 99  */	virtual void RealtimeFlagCaptured(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, bool MatchMade);
	/* 100 */	virtual void RealtimeMedal(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 GameCategoryId, int32 GameMode, bool MatchMade, int32 MedalType, int32 MedalCount);
	/* 101 */	virtual void RealtimePilotedVehicle(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, bool MatchMade, int32 VehicleId, uint64 TimeMS, int32 Distance);
	/* 102 */	virtual void RivalID(wchar_t *UserId, GUID PlayerSessionId, int64 RivalID);
	/* 103 */	virtual void SectionEnd(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId, int32 MissionId);
	/* 104 */	virtual void SectionStart(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 MissionId);
	/* 105 */	virtual void SectionStats(wchar_t *UserId, GUID PlayerSessionId, int32 MissionId, int32 SectionId, int32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds);
	/* 106 */	virtual void SessionSizeUpdate(wchar_t *UserId, GUID PlayerSessionId, int32 SessionSize, int32 SessionSizeMax);
	/* 107 */	virtual void SizeIsEverything(wchar_t *UserId, GUID PlayerSessionId);
	/* 108 */	virtual void SkeetShooter(wchar_t *UserId, GUID PlayerSessionId);
	/* 109 */	virtual void SkullClaimed(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SkullId, int32 DifficultyId);
	/* 110 */	virtual void SoloMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed);
	/* 111 */	virtual void SoloSpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId);
	/* 112 */	virtual void SpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 MissionId, int32 DifficultyId, bool IsCoop);
	/* 113 */	virtual void Supercombine(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId);
	/* 114 */	virtual void SurvivalSpace(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *SurvivalSpace);
	/* 115 */	virtual void TerminalFound(wchar_t *UserId, GUID PlayerSessionId, int32 TerminalId);
	/* 116 */	virtual void TerminalId(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SkullId, int32 DifficultyId);
	/* 117 */	virtual void TicketsEarned(wchar_t *UserId, GUID PlayerSessionId, int32 TicketCount);
	/* 118 */	virtual void TitleCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId);
	/* 119 */	virtual void TitleLaunched(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId);
	/* 120 */	virtual void ValhallaSign(wchar_t *UserId, GUID PlayerSessionId, int32 SignId);
	/* 121 */	virtual void ViewOffer(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid);
	/* 122 */	virtual void VIPStatusEarned(wchar_t *UserId, GUID PlayerSessionId);
	/* 123 */	virtual void WhatAboutTanksDestroyed(wchar_t *UserId, GUID PlayerSessionId);
	/* 124 */	virtual void WonWarGame(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId);
	/* 125 */	virtual void ZanzibarSign(wchar_t *UserId, GUID PlayerSessionId, int32 SignId);
	/* 126 */	virtual void FirefightGameResults(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, bool MatchMade, uint64 TimePlayedMS, uint32 Kills, uint32 MostKillsInARow, uint32 SetsCompleted, uint32 WavesCompleted, uint32 GeneratorsDestroyed);
	/* 127 */	virtual void EnemyDefeated_0(); // probably zombie defeated as these are in alphabetical order
	/* 128 */	virtual void Member128();
	/* 129 */	virtual void Member129();
	/* 130 */	virtual void Member130();
	/* 131 */	virtual void Member131();
	/* 132 */	virtual void Member132();
	/* 133 */	virtual void Member133();
	/* 134 */	virtual __int64 Member134(__int64);
	/* 135 */	virtual void Member135();
	/* 136 */	virtual GUID *__fastcall GetPlayerSessionId();
	/* 137 */	virtual void Member137();
	/* 138 */	virtual void CheckpointSaved();
	/* 139 */	virtual void Member139();

	struct __declspec(align(8)) UnknownType
	{
		__int64 qword0;
		__int64 *qword1;
		__int64 *qword2;
		__int32 dword0;
		__int32 dword1;
		__int64 qword4;
		__int64 *qword5;
		__int64 *qword6;
		__int32 dword2;
		__int32 dword3;
		__int32 dword4;
		__int32 dword5;
	};

	__int16 word0;
	__int16 word1;
	GUID playerSessionId;
	__unaligned __declspec(align(1)) __int64 qword0;
	__unaligned __declspec(align(1)) __int64 qword1;
	__unaligned __declspec(align(1)) __int64 qword2;
	__unaligned __declspec(align(1)) __int64 qword3;
	__unaligned __declspec(align(1)) __int64 qword4;
	__unaligned __declspec(align(1)) __int64 qword5;
	__unaligned __declspec(align(1)) __int64 qword6;
	__unaligned __declspec(align(1)) __int64 qword7;
	__int32 dword0;
	__int32 dword1;
	__int32 dword2;
	_RTL_CRITICAL_SECTION rtlCriticalSection;
	__int64 qword8;
	UnknownType unknownStruct;
	__int64 qword9;
	__int64 qwordA;
	__int64 qwordB;


};

inline void IGameEvents::AchievementEarned(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 AchievementId)
{
}

inline void IGameEvents::AshesToAshes(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::Assist(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade)
{
}

inline void IGameEvents::AudioLogClaimed(wchar_t *UserId, GUID PlayerSessionId, int32 AudioLogId)
{
}

inline void IGameEvents::Base(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::Betrayal(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade)
{
}

inline void IGameEvents::BIFactControllerSettings(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 ControllerConfigurationID, bool LookInverted)
{
}

inline void IGameEvents::BIFactDeepLink(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::BIFactDeepLinkRecieve(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL)
{
}

inline void IGameEvents::BIFactDeepLinkSend(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DeepLinkCorrelationID, wchar_t *DeepLinkURL)
{
}

inline void IGameEvents::BIFactDualWield(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 LeftWeaponID, int32 RightWeaponID, uint64 DualWieldTimeStamp)
{
}

inline void IGameEvents::BIFactGameSession(wchar_t *UserId, GUID PlayerSessionId, uint64 SessionStartTimeStamp, uint64 SessionEndTimeStamp, wchar_t *HaloTitleID, uint64 SubTitleStartTimeStamp, uint64 SubTitleEndTimeStamp, int32 GameCategoryID, wchar_t *LocaleID, int32 MapID, int32 ArmorID, uint64 SkullsUsed, wchar_t *HopperID, int32 PlayerCount, bool Matchmade, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, bool Won, uint64 Score, uint64 TeamScore, int32 Standing, bool FirstPlace, int32 Kills, int32 Deaths, int32 Assists, int32 Betrayals, int32 Suicides)
{
}

inline void IGameEvents::BIFactLoadout(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, int32 GameCategoryID, int32 PrimaryWeaponID, int32 SecondaryWeaponID, int32 GrenadeID, int32 ShieldID)
{
}

inline void IGameEvents::BIFactMatchmaking(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *LobbyID, uint64 LobbyEntryTimeStamp, bool JoinedMatch, uint64 JoinMatchTimeStamp, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, int32 PartySize, GUID PartyID)
{
}

inline void IGameEvents::BIFactMatchmakingDetails(wchar_t *UserId, GUID PlayerSessionId, int32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, uint64 LobbyEntryTimeStamp, uint64 LobbyExitTimeStamp, int32 ExitReason, wchar_t *GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, int32 NumPlayers, int32 NumPreserveSessionTicketsCreated)
{
}

inline void IGameEvents::BIFactMedia(wchar_t *UserId, GUID PlayerSessionId, bool IsGuest, wchar_t *HaloTitleID, uint64 MediaStartTimeStamp, bool WasSkipped, uint64 MediaSkipTimeStamp, wchar_t *MediaID)
{
}

inline void IGameEvents::BirdOfPrey(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::BitsAndPiecesDestroyed(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::BroadcastingAssist(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 CurrentAssists)
{
}

inline void IGameEvents::BroadcastingDeath(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t *VictimXuid, uint32 VictimTeamId, wchar_t *KillerXuid, uint32 KillerTeamId, wchar_t *AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentDeaths)
{
}

inline void IGameEvents::BroadcastingHeartbeat(wchar_t *UserId, GUID PlayerSessionId, int64 Heartbeat)
{
}

inline void IGameEvents::BroadcastingKill(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t *VictimXuid, uint32 VictimTeamId, wchar_t *KillerXuid, uint32 KillerTeamId, wchar_t *AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentKills)
{
}

inline void IGameEvents::BroadcastingMatchEnd(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp)
{
}

inline void IGameEvents::BroadcastingMatchRoundEnd(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp)
{
}

inline void IGameEvents::BroadcastingMatchRoundStart(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 RoundNumber)
{
}

inline void IGameEvents::BroadcastingMatchStart(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MapVariantID, int32 GameVariantID, wchar_t *PlaylistID)
{
}

inline void IGameEvents::BroadcastingMedal(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MedalId)
{
}

inline void IGameEvents::BroadcastingPlayerJoined(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId)
{
}

inline void IGameEvents::BroadcastingPlayerLeft(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp)
{
}

inline void IGameEvents::BroadcastingPlayerSpawn(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp)
{
}

inline void IGameEvents::BroadcastingPlayerSwitchedTeams(wchar_t *UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId, wchar_t *WebColor)
{
}

inline void IGameEvents::BroadcastingScore(wchar_t *UserId, GUID PlayerSessionId, int32 ControllerIndex, int64 Timestamp, int32 CurrentRoundScore, int32 CurrentTotalScore, int32 CurrentRoundTeamScore, int32 CurrentTotalTeamScore)
{
}

inline void IGameEvents::BroadcastingStart(wchar_t *UserId, GUID PlayerSessionId, uint32 GameType, uint32 Map, uint32 TopPlayerRank, wchar_t *PlayerIDs, GUID MatchID, bool PlayerIsCaster, int64 MatchStartTime)
{
}

inline void IGameEvents::CampaignDifficulty(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *CampaignDifficulty)
{
}

inline void IGameEvents::ChallengeCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 ChallengeId)
{
}

inline void IGameEvents::ClassicModeSwitched(wchar_t *UserId, GUID PlayerSessionId, int32 MapId)
{
}

inline void IGameEvents::CleverGirl(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::ClueClaimed(wchar_t *UserId, GUID PlayerSessionId, int32 ClueId)
{
}

inline void IGameEvents::CoopMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MissionId, int32 MapId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, int32 DifficultyId)
{
}

inline void IGameEvents::CoopSpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId)
{
}

inline void IGameEvents::CompletionCount(wchar_t *UserId, GUID PlayerSessionId, int32 Count)
{
}

inline void IGameEvents::Customization(wchar_t *UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2, wchar_t *ServiceId, wchar_t *ClanId, int32 AvatarId, int32 NameplateId)
{
}

inline void IGameEvents::DashboardContext(wchar_t *UserId, GUID PlayerSessionId, wchar_t *DashboardContext)
{
}

inline void IGameEvents::Death(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot)
{
}

inline void IGameEvents::DollFound(wchar_t *UserId, GUID PlayerSessionId, int32 DollId)
{
}

inline void IGameEvents::EliteWin(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, bool MatchMade)
{
}

inline void IGameEvents::Emblem(wchar_t *UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2)
{
}

inline void IGameEvents::EnemyDefeated(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t *HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot)
{
}

inline void IGameEvents::FriendsBestedOnHeroLeaderboard(wchar_t *UserId, GUID PlayerSessionId, int32 LeaderboardId, int32 LeaderboardRows)
{
}

inline void IGameEvents::GameProgress(wchar_t *UserId, GUID PlayerSessionId, float CompletionPercent)
{
}

inline void IGameEvents::GameVarSaved(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 BaseGameCategory, wchar_t *GameVarName)
{
}

inline void IGameEvents::GrenadeStick(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId)
{
}

inline void IGameEvents::HelloNurse(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::InGamePresence(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitle, int32 CampaignDifficulty, int32 MultiplayerMap)
{
}

inline void IGameEvents::ISeeYou(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::Joinability(wchar_t *UserId, GUID PlayerSessionId, bool InGame)
{
}

inline void IGameEvents::Lobby(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *Lobby)
{
}

inline void IGameEvents::MainMenuPresence(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MainMenuPresence)
{
}

inline void IGameEvents::MapVarSaved(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 BaseMapId, wchar_t *MapVarName)
{
}

inline void IGameEvents::MatchmakingHopper(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MatchmakingHopper)
{
}

inline void IGameEvents::MediaUsage(wchar_t *AppSessionId, wchar_t *AppSessionStartDateTime, uint32 UserIdType, wchar_t *UserId, wchar_t *SubscriptionTierType, wchar_t *SubscriptionTier, wchar_t *MediaType, wchar_t *ProviderId, wchar_t *ProviderMediaId, wchar_t *ProviderMediaInstanceId, GUID BingId, uint64 MediaLengthMs, uint32 MediaControlAction, float PlaybackSpeed, uint64 MediaPositionMs, uint64 PlaybackDurationMs, wchar_t *AcquisitionType, wchar_t *AcquisitionContext, wchar_t *AcquisitionContextType, wchar_t *AcquisitionContextId, int32 PlaybackIsStream, int32 PlaybackIsTethered, wchar_t *MarketplaceLocation, wchar_t *ContentLocale, float TimeZoneOffset, uint32 ScreenState)
{
}

inline void IGameEvents::MeldOfferPresented(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, wchar_t *Page, int32 SourceTileIndex)
{
}

inline void IGameEvents::MeldOfferResponded(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, int32 UpsellOutcome)
{
}

inline void IGameEvents::MeldPageAction(wchar_t *UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t *Page, wchar_t *TemplateId, wchar_t *DestinationPage, wchar_t *Content, int32 SourceTileIndex, int32 SourceTileX, int32 SourceTileY, int32 SourceTileWidth, int32 SourceTileHeight)
{
}

inline void IGameEvents::MeldPageView(wchar_t *UserId, GUID PlayerSessionId, wchar_t *Page, wchar_t *RefererPage, int32 PageTypeId, wchar_t *PageTags, wchar_t *TemplateId, wchar_t *Content, wchar_t *FilterContext, int32 FilterDirection)
{
}

inline void IGameEvents::MissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 GameCategoryId, bool Coop, uint64 TimePlayedMS, uint64 DatePlayedUTC, int32 DifficultyId, uint64 MissionScore64, uint64 SkullUsedFlags, int32 NumPlayers, wchar_t *PlayerSectionStats, int32 Kills, float Multiplier, int32 Penalties, float SkullMultiplier, int32 TotalSoloMissionsComplete, int32 TotalCoopMissionsComplete)
{
}

inline void IGameEvents::MortardomWraithsKilled(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::MultiplayerGameEngine(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MultiplayerGameEngine)
{
}

inline void IGameEvents::MultiplayerMap(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *MultiplayerMap)
{
}

inline void IGameEvents::MultiplayerRoundEnd(wchar_t *UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId, float TimeInSeconds, int32 ExitStatusId)
{
}

inline void IGameEvents::MultiplayerRoundStart(wchar_t *UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId)
{
}

inline void IGameEvents::NappersCaught(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::NewsStoryRead(wchar_t *UserId, GUID PlayerSessionId, wchar_t *StoryId)
{
}

inline void IGameEvents::ObjectiveEnd(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId, int32 ExitStatusId)
{
}

inline void IGameEvents::ObjectiveStart(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId)
{
}

inline void IGameEvents::PageAction(wchar_t *UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t *Page, wchar_t *TemplateId, wchar_t *DestinationPage, wchar_t *Content)
{
}

inline void IGameEvents::PageView(wchar_t *UserId, GUID PlayerSessionId, wchar_t *Page, wchar_t *RefererPage, int32 PageTypeId, wchar_t *PageTags, wchar_t *TemplateId, wchar_t *Content)
{
}

inline void IGameEvents::PhantomHunter(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::PigsCanFly(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::PlayerCheckedInToday(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId)
{
}

inline void IGameEvents::PlayerDefeated(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 EnemyWeaponId, float LocationX, float LocationY, float LocationZ)
{
}

inline void IGameEvents::PlayerGameResults(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 GameIndexByCategory, int32 GameIndexByTitle, int32 GameIndexByTitleCategory, int32 MapId, int32 GameCategoryId, bool MatchMade, bool Won, uint64 TimePlayedMS, uint64 DatePlayedUTC, uint64 Score64, int32 Standing, bool FirstPlace, int32 MedalCount, int32 Kills, int32 Deaths, int32 Assists, int32 HeadShots, int32 MostKillsInARow, wchar_t *CustomStat1ID, int32 CustomStat1, wchar_t *CustomStat2ID, int32 CustomStat2, wchar_t *CustomStat3ID, int32 CustomStat3, wchar_t *CustomStat4ID, int32 CustomStat4, GUID MatchId)
{
}

inline void IGameEvents::PlayerGameResultsDamageStat(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 DamageReportingType, int32 DamageStatisticType, int32 DamageCount, int32 GameCategoryId)
{
}

inline void IGameEvents::PlayerGameResultsGriefingStat(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
}

inline void IGameEvents::PlayerGameResultsGriefingStats(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
}

inline void IGameEvents::PlayerGameResultsInterestStats(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameCategoryId, int32 GameIndex, int32 MapId, bool MatchMade, int32 OrdnanceDrops, int32 OrdnanceStrikes, uint64 TimeMSDriven, int32 UnitsDriven, uint64 TimeMSPiloted, int32 UnitsPiloted, uint64 TimeMSPassenger, int32 UnitsMovedPassenger, uint64 TimeMSOnFoot, int32 UnitsMovedOnFoot, int32 DriverAssists, int32 ArmorAbilityUseJetpack, int32 ArmorAbilityUseHologram, int32 ArmorAbilityUseReflectiveShield, int32 ArmorAbilityUseActiveCamo, int32 ArmorAbilityUseThrusterPack, int32 ArmorAbilityUseAutoTurret, int32 ArmorAbilityUseXRay)
{
}

inline void IGameEvents::PlayerGameResultsMedal(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 MedalType, int32 MedalCount)
{
}

inline void IGameEvents::PlayerSessionEnd(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId)
{
}

inline void IGameEvents::PlayerSessionPause(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId)
{
}

inline void IGameEvents::PlayerSessionResume(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId)
{
}

inline void IGameEvents::PlayerSessionStart(wchar_t *UserId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId)
{
}

inline void IGameEvents::PlayerSpawned(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, float LocationX, float LocationY, float LocationZ)
{
}

inline void IGameEvents::PlaylistCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, uint32 PlaylistId, uint64 Score64, uint64 TimeMS, int32 Penalties, wchar_t *MissionStats, bool IsCoop)
{
}

inline void IGameEvents::PlaylistProgress(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 PlaylistId, int32 NumMapsCompleted, uint64 Score64, bool IsCoop, int32 NumPlayers, bool ShouldPostTime, uint64 TotalPlayListTimeMS)
{
}

inline void IGameEvents::RankedStatsDNFInfo(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double FinishesOverStarts, int32 FinishesMinusStarts, int32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts)
{
}

inline void IGameEvents::RankedStatsOverride(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked)
{
}

inline void IGameEvents::RankedStatsPenalty(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, int32 NumPenaltiesApplied)
{
}

inline void IGameEvents::RankedStatsUpdate(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked, bool PenaltyApplied)
{
}

inline void IGameEvents::RankedUpSpartanIv(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SpartanIvRank, int32 SpecialisationType)
{
}

inline void IGameEvents::RealtimeFlagCaptured(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, bool MatchMade)
{
}

inline void IGameEvents::RealtimeMedal(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 GameCategoryId, int32 GameMode, bool MatchMade, int32 MedalType, int32 MedalCount)
{
}

inline void IGameEvents::RealtimePilotedVehicle(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, bool MatchMade, int32 VehicleId, uint64 TimeMS, int32 Distance)
{
}

inline void IGameEvents::RivalID(wchar_t *UserId, GUID PlayerSessionId, int64 RivalID)
{
}

inline void IGameEvents::SectionEnd(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId, int32 MissionId)
{
}

inline void IGameEvents::SectionStart(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 MissionId)
{
}

inline void IGameEvents::SectionStats(wchar_t *UserId, GUID PlayerSessionId, int32 MissionId, int32 SectionId, int32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds)
{
}

inline void IGameEvents::SessionSizeUpdate(wchar_t *UserId, GUID PlayerSessionId, int32 SessionSize, int32 SessionSizeMax)
{
}

inline void IGameEvents::SizeIsEverything(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::SkeetShooter(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::SkullClaimed(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SkullId, int32 DifficultyId)
{
}

inline void IGameEvents::SoloMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed)
{
}

inline void IGameEvents::SoloSpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 DifficultyId)
{
}

inline void IGameEvents::SpartanOpsMissionCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 MapId, int32 MissionId, int32 DifficultyId, bool IsCoop)
{
}

inline void IGameEvents::Supercombine(wchar_t *UserId, int32 SectionId, GUID PlayerSessionId, wchar_t *MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId)
{
}

inline void IGameEvents::SurvivalSpace(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, wchar_t *SurvivalSpace)
{
}

inline void IGameEvents::TerminalFound(wchar_t *UserId, GUID PlayerSessionId, int32 TerminalId)
{
}

inline void IGameEvents::TerminalId(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, int32 SkullId, int32 DifficultyId)
{
}

inline void IGameEvents::TicketsEarned(wchar_t *UserId, GUID PlayerSessionId, int32 TicketCount)
{
}

inline void IGameEvents::TitleCompleted(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId)
{
}

inline void IGameEvents::TitleLaunched(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId)
{
}

inline void IGameEvents::ValhallaSign(wchar_t *UserId, GUID PlayerSessionId, int32 SignId)
{
}

inline void IGameEvents::ViewOffer(wchar_t *UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid)
{
}

inline void IGameEvents::VIPStatusEarned(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::WhatAboutTanksDestroyed(wchar_t *UserId, GUID PlayerSessionId)
{
}

inline void IGameEvents::WonWarGame(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId)
{
}

inline void IGameEvents::ZanzibarSign(wchar_t *UserId, GUID PlayerSessionId, int32 SignId)
{
}

inline void IGameEvents::FirefightGameResults(wchar_t *UserId, GUID PlayerSessionId, wchar_t *HaloTitleId, bool MatchMade, uint64 TimePlayedMS, uint32 Kills, uint32 MostKillsInARow, uint32 SetsCompleted, uint32 WavesCompleted, uint32 GeneratorsDestroyed)
{
}

inline void IGameEvents::EnemyDefeated_0()
{
}

inline void IGameEvents::Member128()
{
}

inline void IGameEvents::Member129()
{
}

inline void IGameEvents::Member130()
{
}

inline void IGameEvents::Member131()
{
}

inline void IGameEvents::Member132()
{
}

inline void IGameEvents::Member133()
{
}

inline __int64 IGameEvents::Member134(__int64)
{
	return 0;
}

inline void IGameEvents::Member135()
{
}

inline GUID *__fastcall IGameEvents::GetPlayerSessionId()
{
	return &playerSessionId;
}

inline void IGameEvents::Member137()
{
}

inline void IGameEvents::CheckpointSaved()
{
}

inline void IGameEvents::Member139()
{
}