import 'package:flutter/material.dart';
import 'package:telescope_goto_app/pages/CalibrationPage.dart';
import 'package:telescope_goto_app/pages/ConnectionManagmentTopPage.dart';
import 'package:telescope_goto_app/pages/ConstraintsPage.dart';
import 'package:telescope_goto_app/pages/PageTemplate.dart';
import 'package:telescope_goto_app/services/Comands/DateComand.dart';
import 'package:telescope_goto_app/services/Comands/LatitudeComand.dart';
import 'package:telescope_goto_app/services/Comands/LongitudeComand.dart';
import 'package:telescope_goto_app/services/Comands/TimeComand.dart';
import 'package:telescope_goto_app/services/Comands/UtcOffsetComand.dart';
import 'package:telescope_goto_app/services/ComunicationInterface.dart';
import 'package:telescope_goto_app/widgets/DateTimeForm.dart';
import 'package:telescope_goto_app/widgets/LocationForm.dart';

class GenerelInformationPage extends StatelessWidget {
  final ComunicationInterface comunicationInterface;
  final LocationFromController locationFromController =
      LocationFromController();
  final DateTimeFormController dateTimeFormController =
      DateTimeFormController();

  GenerelInformationPage({@required this.comunicationInterface, Key key})
      : super(key: key);

  void navigateNextPage(BuildContext context) {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => ConstraintsPage(
          comunicationInterface: this.comunicationInterface,
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return PageTemplate(
      header: "Generel Information",
      description: "To enable tracking we need location and time data.",
      child: Expanded(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Column(
              children: [
                Column(
                  children: [
                    LocationForm(
                      controller: this.locationFromController,
                    ),
                    Divider(),
                    DataTimeForm(
                      controller: this.dateTimeFormController,
                    ),
                  ],
                )
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                RaisedButton(
                  child: Text("Skip"),
                  onPressed: () {
                    this.navigateNextPage(context);
                  },
                ),
                RaisedButton(
                  child: Text("Done"),
                  onPressed: () {
                    comunicationInterface.recive().listen((event) {});
                    locationFromController.getGPSCoords().then((value) {
                      comunicationInterface
                          .sendComand(LatitudeComand(value["latitude"]));

                      comunicationInterface
                          .sendComand(LongitudeComand(value["longitude"]));
                    });
                    DateTime dateTime = dateTimeFormController.getDateTime();
                    comunicationInterface.sendComand(DateComand(dateTime));
                    comunicationInterface.sendComand(TimeComand(dateTime));
                    comunicationInterface.sendComand(UtcOffsetComand(dateTime));

                    this.navigateNextPage(context);
                  },
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
