#pragma once

#include "MainPage.xaml.h"
#include "Models\RoomModel.h"
#include "pch.h"

using namespace Windows::Storage;

ref class GeoFence sealed
{
public:
	GeoFence();
	virtual ~GeoFence();

	void RegisterBackgroundTask();
	void addGeoFence(RoomModel^ room);

private:
	RoomModel^ ReadRoomFromStorage();
	StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
	Windows::Devices::Geolocation::Geofencing::Geofence^ GenerateGeoFence(RoomModel^ room);
	void RequestLocationAccess();
	void GenerateAllGeoFences();
	void OnCompleted(Windows::ApplicationModel::Background::BackgroundTaskRegistration^ sender, Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs^ e);

	Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence^>^ geofences;

	Windows::ApplicationModel::Background::BackgroundTaskRegistration^ geofenceTask;
	Windows::Foundation::EventRegistrationToken taskCompletedToken;

};