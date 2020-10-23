import 'package:flutter/material.dart';

class DataTimeForm extends StatefulWidget {
  DateTimeFormController controller;
  DataTimeForm({Key key, @required this.controller}) : super(key: key);

  @override
  _DataTimeFormState createState() => _DataTimeFormState(controller);
}

class _DataTimeFormState extends State<DataTimeForm> {
  bool useDeviceTime = true;

  _DataTimeFormState(DateTimeFormController controller) {
    controller.getDateTime = getDateTime;
  }

  DateTime getDateTime() {
    if (this.useDeviceTime) {
      return DateTime.now();
    }
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Column(
        children: [
          Text(
            "Date / Time:",
          ),
          SwitchListTile(
            value: this.useDeviceTime,
            onChanged: (current) =>
                this.setState(() => this.useDeviceTime = current),
            title: Text("Use device time"),
          ),
          if (!this.useDeviceTime)
            Padding(
              padding: EdgeInsets.fromLTRB(32.0, 0, 16.0, 0),
              child: Column(
                children: [
                  TextField(
                    decoration: InputDecoration(labelText: "Date MM/DD/YY"),
                  ),
                  TextField(
                    decoration: InputDecoration(labelText: "Time HH:MM:SS"),
                  ),
                  TextField(
                    decoration: InputDecoration(labelText: "UTC offset sHH"),
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }
}

class DateTimeFormController {
  DateTimeFormController();

  DateTime Function() getDateTime;
}
