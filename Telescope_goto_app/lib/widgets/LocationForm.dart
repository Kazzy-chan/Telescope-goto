import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:geolocator/geolocator.dart';
import 'package:telescope_goto_app/services/GPSCoord.dart';
import 'package:telescope_goto_app/services/LatitudeLongitude.dart';

class LocationForm extends StatefulWidget {
  final LocationFromController controller;

  const LocationForm({Key key, @required this.controller}) : super(key: key);

  @override
  _LocationFormState createState() => _LocationFormState(controller);
}

class _LocationFormState extends State<LocationForm> {
  bool useGPS = false;
  double latitude;
  double longitude;

  _LocationFormState(LocationFromController controller) {
    controller.getGPSCoords = getGPSCoords;
  }

  Future<Map<String, GPSCoord>> getGPSCoords() async {
    if (useGPS) {
      Position position =
          await getCurrentPosition(desiredAccuracy: LocationAccuracy.high);
      return {
        "latitude": LatitudeLongitude(position.latitude).toGPSCoord(),
        "longitude": LatitudeLongitude(position.longitude).toGPSCoord()
      };
    } else {
      return {
        "latitude": LatitudeLongitude(latitude).toGPSCoord(),
        "longitude": LatitudeLongitude(longitude).toGPSCoord()
      };
    }
  }

  @override
  Widget build(BuildContext context) {
    if (this.useGPS) {
      requestPermission().then((permission) {
        if (permission == LocationPermission.denied ||
            permission == LocationPermission.deniedForever) {
          this.setState(() {
            this.useGPS = false;
          });
        }
      });
    }

    return Container(
      child: Column(
        children: [
          Text(
            "Location Data:",
          ),
          SwitchListTile(
            value: this.useGPS,
            onChanged: (current) => this.setState(() => this.useGPS = current),
            title: Text("Use GPS"),
          ),
          if (!this.useGPS)
            Padding(
              padding: EdgeInsets.fromLTRB(32.0, 0, 16.0, 0),
              child: Column(
                children: [
                  TextField(
                    keyboardType: TextInputType.number,
                    decoration: InputDecoration(labelText: "Latitude"),
                  ),
                  TextField(
                    keyboardType: TextInputType.number,
                    decoration: InputDecoration(labelText: "Longitude"),
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }
}

class LocationFromController {
  LocationFromController();

  Future<Map<String, GPSCoord>> Function() getGPSCoords;
}
