import 'package:flutter/material.dart';
import 'package:telescope_goto_app/pages/ConstraintsPage.dart';
import 'package:telescope_goto_app/pages/GenerelInformationPage.dart';
import 'package:telescope_goto_app/services/ComunicationInterface.dart';

class ConnectionManagmentTopPage extends StatefulWidget {
  final ComunicationInterface comunicationInterface;
  const ConnectionManagmentTopPage(
      {Key key, @required this.comunicationInterface})
      : super(key: key);

  @override
  _ConnectionManagmentTopPageState createState() =>
      _ConnectionManagmentTopPageState();
}

class _ConnectionManagmentTopPageState
    extends State<ConnectionManagmentTopPage> {
  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: GenerelInformationPage(
        comunicationInterface: this.widget.comunicationInterface,
      ),
    );
  }
}
