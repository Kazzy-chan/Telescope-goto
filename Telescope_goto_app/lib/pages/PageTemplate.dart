import 'package:flutter/material.dart';

class PageTemplate extends StatelessWidget {
  final Widget child;
  final String header;
  final String description;
  const PageTemplate(
      {Key key, @required this.child, this.header = "", this.description = ""})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Padding(
          padding: EdgeInsets.all(16.0),
          child: Column(
            children: [
              Center(
                child: Text(
                  this.header,
                  textScaleFactor: 1.5,
                  textAlign: TextAlign.center,
                ),
              ),
              Center(
                child: Text(
                  this.description,
                  textScaleFactor: 1.1,
                  textAlign: TextAlign.center,
                ),
              ),
              Divider(
                height: 32,
              ),
              this.child
            ],
          ),
        ),
      ),
    );
  }
}
