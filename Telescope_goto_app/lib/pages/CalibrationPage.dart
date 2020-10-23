import 'package:flutter/material.dart';
import 'package:telescope_goto_app/pages/PageTemplate.dart';
import 'package:telescope_goto_app/services/Comands/CalibrationComand.dart';
import 'package:telescope_goto_app/services/ComunicationInterface.dart';
import 'package:telescope_goto_app/widgets/ControllPad.dart';

class CalibrationPage extends StatelessWidget {
  final ComunicationInterface comunicationInterface;
  const CalibrationPage({Key key, @required this.comunicationInterface})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return PageTemplate(
      header: "Calibration",
      description:
          "To know where how to move the telescope we need to know where it points to.",
      child: Expanded(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Column(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Text(
                  "Move the telescope with the Controll Pad below so that it points to the polar star",
                  textAlign: TextAlign.center,
                ),
                Divider(),
                ControllPad(
                  comunicationInterface: this.comunicationInterface,
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                RaisedButton(
                  onPressed: () {},
                  child: Text("Skip"),
                ),
                RaisedButton(
                  onPressed: () {
                    comunicationInterface
                        .sendComand(CalibrationRaComand("02:33:33"));
                    comunicationInterface
                        .sendComand(CalibrationDecComand("+89*15:48"));
                  },
                  child: Text("Done"),
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
