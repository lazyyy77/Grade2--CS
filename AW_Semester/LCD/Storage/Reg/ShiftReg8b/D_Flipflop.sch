<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_4" />
        <signal name="XLXN_8" />
        <signal name="C" />
        <signal name="R_" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="S_" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_31" />
        <signal name="D" />
        <signal name="XLXN_35" />
        <signal name="Q" />
        <signal name="Q_" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="R_" />
        <port polarity="Input" name="S_" />
        <port polarity="Input" name="D" />
        <port polarity="Output" name="Q" />
        <port polarity="Output" name="Q_" />
        <blockdef name="nand3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="216" y1="-128" y2="-128" x1="256" />
            <circle r="12" cx="204" cy="-128" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <block symbolname="nand3" name="XLXI_7">
            <blockpin signalname="XLXN_23" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="S_" name="I2" />
            <blockpin signalname="XLXN_22" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_8">
            <blockpin signalname="R_" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_22" name="I2" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_10">
            <blockpin signalname="R_" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_31" name="I2" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_9">
            <blockpin signalname="XLXN_27" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_23" name="I2" />
            <blockpin signalname="XLXN_31" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_11">
            <blockpin signalname="Q_" name="I0" />
            <blockpin signalname="XLXN_23" name="I1" />
            <blockpin signalname="S_" name="I2" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_12">
            <blockpin signalname="R_" name="I0" />
            <blockpin signalname="XLXN_31" name="I1" />
            <blockpin signalname="Q" name="I2" />
            <blockpin signalname="Q_" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1040" y="848" name="XLXI_7" orien="R0" />
        <instance x="1040" y="1168" name="XLXI_8" orien="R0" />
        <instance x="1040" y="1488" name="XLXI_9" orien="R0" />
        <instance x="1040" y="1808" name="XLXI_10" orien="R0" />
        <branch name="C">
            <wire x2="880" y1="1200" y2="1200" x1="640" />
            <wire x2="880" y1="1200" y2="1360" x1="880" />
            <wire x2="1040" y1="1360" y2="1360" x1="880" />
            <wire x2="1040" y1="1040" y2="1040" x1="880" />
            <wire x2="880" y1="1040" y2="1200" x1="880" />
        </branch>
        <branch name="R_">
            <wire x2="1040" y1="1104" y2="1104" x1="960" />
            <wire x2="960" y1="1104" y2="1744" x1="960" />
            <wire x2="960" y1="1744" y2="1920" x1="960" />
            <wire x2="1520" y1="1920" y2="1920" x1="960" />
            <wire x2="1600" y1="1920" y2="1920" x1="1520" />
            <wire x2="1040" y1="1744" y2="1744" x1="960" />
            <wire x2="1520" y1="1424" y2="1920" x1="1520" />
            <wire x2="1600" y1="1424" y2="1424" x1="1520" />
        </branch>
        <branch name="XLXN_22">
            <wire x2="1360" y1="880" y2="880" x1="960" />
            <wire x2="960" y1="880" y2="976" x1="960" />
            <wire x2="1040" y1="976" y2="976" x1="960" />
            <wire x2="1360" y1="720" y2="720" x1="1296" />
            <wire x2="1360" y1="720" y2="880" x1="1360" />
        </branch>
        <branch name="XLXN_23">
            <wire x2="1040" y1="784" y2="928" x1="1040" />
            <wire x2="1360" y1="928" y2="928" x1="1040" />
            <wire x2="1360" y1="928" y2="1040" x1="1360" />
            <wire x2="1360" y1="1040" y2="1200" x1="1360" />
            <wire x2="1376" y1="1040" y2="1040" x1="1360" />
            <wire x2="1600" y1="1040" y2="1040" x1="1376" />
            <wire x2="1360" y1="1200" y2="1200" x1="1040" />
            <wire x2="1040" y1="1200" y2="1296" x1="1040" />
            <wire x2="1360" y1="1040" y2="1040" x1="1296" />
        </branch>
        <branch name="S_">
            <wire x2="960" y1="560" y2="656" x1="960" />
            <wire x2="1040" y1="656" y2="656" x1="960" />
            <wire x2="1520" y1="560" y2="560" x1="960" />
            <wire x2="1600" y1="560" y2="560" x1="1520" />
            <wire x2="1520" y1="560" y2="976" x1="1520" />
            <wire x2="1600" y1="976" y2="976" x1="1520" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="1040" y1="720" y2="720" x1="800" />
            <wire x2="800" y1="720" y2="1840" x1="800" />
            <wire x2="1360" y1="1840" y2="1840" x1="800" />
            <wire x2="1040" y1="1424" y2="1504" x1="1040" />
            <wire x2="1360" y1="1504" y2="1504" x1="1040" />
            <wire x2="1360" y1="1504" y2="1680" x1="1360" />
            <wire x2="1360" y1="1680" y2="1840" x1="1360" />
            <wire x2="1360" y1="1680" y2="1680" x1="1296" />
        </branch>
        <branch name="XLXN_31">
            <wire x2="1280" y1="1568" y2="1568" x1="1040" />
            <wire x2="1040" y1="1568" y2="1616" x1="1040" />
            <wire x2="1360" y1="1440" y2="1440" x1="1280" />
            <wire x2="1280" y1="1440" y2="1568" x1="1280" />
            <wire x2="1360" y1="1360" y2="1360" x1="1296" />
            <wire x2="1360" y1="1360" y2="1440" x1="1360" />
            <wire x2="1600" y1="1360" y2="1360" x1="1360" />
        </branch>
        <branch name="D">
            <wire x2="1040" y1="1680" y2="1680" x1="640" />
        </branch>
        <instance x="1600" y="1168" name="XLXI_11" orien="R0" />
        <instance x="1600" y="1488" name="XLXI_12" orien="R0" />
        <branch name="Q">
            <wire x2="1840" y1="1248" y2="1248" x1="1600" />
            <wire x2="1600" y1="1248" y2="1296" x1="1600" />
            <wire x2="1920" y1="1120" y2="1120" x1="1840" />
            <wire x2="1840" y1="1120" y2="1248" x1="1840" />
            <wire x2="1920" y1="1040" y2="1040" x1="1856" />
            <wire x2="2000" y1="1040" y2="1040" x1="1920" />
            <wire x2="1920" y1="1040" y2="1120" x1="1920" />
        </branch>
        <branch name="Q_">
            <wire x2="1600" y1="1104" y2="1184" x1="1600" />
            <wire x2="1920" y1="1184" y2="1184" x1="1600" />
            <wire x2="1920" y1="1184" y2="1360" x1="1920" />
            <wire x2="2000" y1="1360" y2="1360" x1="1920" />
            <wire x2="1920" y1="1360" y2="1360" x1="1856" />
        </branch>
        <iomarker fontsize="28" x="640" y="1200" name="C" orien="R180" />
        <iomarker fontsize="28" x="640" y="1680" name="D" orien="R180" />
        <iomarker fontsize="28" x="1600" y="1920" name="R_" orien="R0" />
        <iomarker fontsize="28" x="1600" y="560" name="S_" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1040" name="Q" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1360" name="Q_" orien="R0" />
    </sheet>
</drawing>