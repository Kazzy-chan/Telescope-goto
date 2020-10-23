import 'package:flutter/material.dart';
import 'package:telescope_goto_app/pages/FindDevice.dart';
import 'package:telescope_goto_app/pages/GenerelInformationPage.dart';
import 'package:telescope_goto_app/pages/CalibrationPage.dart';
import 'package:telescope_goto_app/widgets/ControllPad.dart';

void main() {
  runApp(App());
}

class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: FindDevice(),
    );
  }
}
