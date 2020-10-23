import 'package:flutter/material.dart';
import 'package:telescope_goto_app/pages/CalibrationPage.dart';
import 'package:telescope_goto_app/pages/PageTemplate.dart';
import 'package:telescope_goto_app/services/Comands/ConstraintComand.dart';
import 'package:telescope_goto_app/services/ComunicationInterface.dart';
import 'package:telescope_goto_app/widgets/ControllPad.dart';

class ConstraintsPage extends StatefulWidget {
  final ComunicationInterface comunicationInterface;
  const ConstraintsPage({Key key, @required this.comunicationInterface})
      : super(key: key);

  @override
  _ConstraintsPageState createState() => _ConstraintsPageState();
}

class _ConstraintsPageState extends State<ConstraintsPage> {
  bool top = false;
  bool bottom = false;

  void navigateNextPage() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => CalibrationPage(
          comunicationInterface: this.widget.comunicationInterface,
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return PageTemplate(
      header: "Constraints",
      description: "Set the Constraints of the Motors",
      child: Expanded(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Column(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Text(
                  "Move one motor after the other to set the upper and lower contraint",
                  textAlign: TextAlign.center,
                ),
                ControllPad(
                  comunicationInterface: this.widget.comunicationInterface,
                ),
                Divider(
                  height: 32,
                ),
                ToggleButtons(
                  children: <Widget>[
                    SizedBox(
                      width: 150,
                      child: Center(child: Text("Motor 1")),
                    ),
                    SizedBox(
                      width: 150,
                      child: Center(child: Text("Motor 2")),
                    ),
                  ],
                  isSelected: [true, false],
                  onPressed: (index) {},
                ),
                SizedBox(
                  height: 16,
                ),
                Row(
                  children: [
                    ButtonTheme(
                      minWidth: 180,
                      child: OutlineButton(
                        child: Text("Set top constraint"),
                        onPressed: () {
                          this
                              .widget
                              .comunicationInterface
                              .sendComand(SetConstraintTopComand(1));
                          this.setState(() {
                            this.top = true;
                          });
                        },
                      ),
                    ),
                    Checkbox(
                      value: this.top,
                      onChanged: (value) {},
                    )
                  ],
                ),
                Row(
                  children: [
                    ButtonTheme(
                      minWidth: 180,
                      child: OutlineButton(
                        child: Text("Set bottom constraint"),
                        onPressed: () {
                          this
                              .widget
                              .comunicationInterface
                              .sendComand(SetConstraintBottomComand(1));
                          this.setState(() {
                            this.bottom = true;
                          });
                        },
                      ),
                    ),
                    Checkbox(
                      value: this.bottom,
                      onChanged: (value) {},
                    )
                  ],
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                RaisedButton(
                  child: Text("Skip"),
                  onPressed: () => this.navigateNextPage(),
                ),
                RaisedButton(
                  child: Text("Done"),
                  onPressed: () => this.navigateNextPage(),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
