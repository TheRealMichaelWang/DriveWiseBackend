#pragma once

namespace DriveWise {
	class accident {
	private:
		double latitude;
		double longitude;

	public:
		accident(double latitude, double longitude) : latitude(latitude), longitude(longitude) { }
	};
}