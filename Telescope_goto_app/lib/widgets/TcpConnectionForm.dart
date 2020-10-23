import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:telescope_goto_app/pages/ConnectionManagmentTopPage.dart';
import 'package:telescope_goto_app/pages/GenerelInformationPage.dart';
import 'package:telescope_goto_app/services/TcpComunicationInterface.dart';

class TcpConnectionForm extends StatefulWidget {
  const TcpConnectionForm({Key key}) : super(key: key);

  @override
  _TcpConnectionFormState createState() => _TcpConnectionFormState();
}

class _TcpConnectionFormState extends State<TcpConnectionForm> {
  String ip;
  int port;
  bool error = false;
  bool loading = false;

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Column(
        children: [
          Row(
            children: [
              Expanded(
                flex: 3,
                child: TextField(
                  onChanged: (value) => setState(() => this.ip = value),
                  decoration: InputDecoration(labelText: "Ip"),
                ),
              ),
              SizedBox(
                width: 8,
              ),
              Expanded(
                flex: 1,
                child: TextField(
                  keyboardType: TextInputType.number,
                  inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                  onChanged: (value) =>
                      setState(() => this.port = num.tryParse(value)),
                  decoration: InputDecoration(labelText: "Port"),
                ),
              )
            ],
          ),
          SizedBox(
            height: 16,
          ),
          RaisedButton(
            onPressed: () async {
              this.setState(() {
                this.error = false;
                this.loading = true;
              });
              TcpComunicationInterface tcpComunicationInterface =
                  TcpComunicationInterface(this.ip, this.port);
              if (await tcpComunicationInterface.connect()) {
                Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => ConnectionManagmentTopPage(
                        comunicationInterface: tcpComunicationInterface,
                      ),
                    ));
                this.setState(() {
                  this.loading = false;
                });
              } else {
                this.setState(() {
                  this.error = true;
                  this.loading = false;
                });
              }
            },
            child: this.loading ? CircularProgressIndicator() : Text("Next"),
          ),
          (this.error ? Text("Could not reach tcp server") : SizedBox()),
        ],
      ),
    );
  }
}
