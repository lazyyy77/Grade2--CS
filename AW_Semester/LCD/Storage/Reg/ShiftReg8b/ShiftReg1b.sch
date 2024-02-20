<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q" />
        <signal name="clk" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="S_IN" />
        <signal name="S_L" />
        <signal name="P_IN" />
        <signal name="XLXN_11" />
        <signal name="Q_" />
        <signal name="R_" />
        <signal name="S_" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="clk" />
        <port polarity="Input" name="S_IN" />
        <port polarity="Input" name="S_L" />
        <port polarity="Input" name="P_IN" />
        <port polarity="Output" name="Q_" />
        <port polarity="Input" name="R_" />
        <port polarity="Input" name="S_" />
        <blockdef name="D_Flipflop">
            <timestamp>2023-12-19T2:33:58</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="D_Flipflop" name="XLXI_1">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="R_" name="R_" />
            <blockpin signalname="S_" name="S_" />
            <blockpin signalname="XLXN_3" name="D" />
            <blockpin signalname="Q" name="Q" />
            <blockpin signalname="Q_" name="Q_" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="S_IN" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="P_IN" name="I0" />
            <blockpin signalname="S_L" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="S_L" name="I" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1616" y="1456" name="XLXI_1" orien="R0">
        </instance>
        <branch name="Q">
            <wire x2="2320" y1="1232" y2="1232" x1="2000" />
        </branch>
        <branch name="clk">
            <wire x2="1616" y1="1232" y2="1232" x1="1360" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1616" y1="1424" y2="1424" x1="1520" />
        </branch>
        <instance x="1264" y="1520" name="XLXI_2" orien="R0" />
        <instance x="864" y="1440" name="XLXI_3" orien="R0" />
        <instance x="864" y="1600" name="XLXI_4" orien="R0" />
        <branch name="XLXN_4">
            <wire x2="1184" y1="1344" y2="1344" x1="1120" />
            <wire x2="1184" y1="1344" y2="1392" x1="1184" />
            <wire x2="1264" y1="1392" y2="1392" x1="1184" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1184" y1="1504" y2="1504" x1="1120" />
            <wire x2="1184" y1="1456" y2="1504" x1="1184" />
            <wire x2="1264" y1="1456" y2="1456" x1="1184" />
        </branch>
        <branch name="S_IN">
            <wire x2="848" y1="1312" y2="1312" x1="400" />
            <wire x2="864" y1="1312" y2="1312" x1="848" />
        </branch>
        <branch name="S_L">
            <wire x2="480" y1="1472" y2="1472" x1="400" />
            <wire x2="720" y1="1472" y2="1472" x1="480" />
            <wire x2="864" y1="1472" y2="1472" x1="720" />
            <wire x2="512" y1="1376" y2="1376" x1="480" />
            <wire x2="480" y1="1376" y2="1472" x1="480" />
        </branch>
        <branch name="P_IN">
            <wire x2="848" y1="1536" y2="1536" x1="400" />
            <wire x2="864" y1="1536" y2="1536" x1="848" />
        </branch>
        <iomarker fontsize="28" x="1360" y="1232" name="clk" orien="R180" />
        <iomarker fontsize="28" x="2320" y="1232" name="Q" orien="R0" />
        <instance x="512" y="1408" name="XLXI_9" orien="R0" />
        <iomarker fontsize="28" x="400" y="1312" name="S_IN" orien="R180" />
        <iomarker fontsize="28" x="400" y="1472" name="S_L" orien="R180" />
        <iomarker fontsize="28" x="400" y="1536" name="P_IN" orien="R180" />
        <branch name="XLXN_11">
            <wire x2="864" y1="1376" y2="1376" x1="736" />
        </branch>
        <branch name="Q_">
            <wire x2="2320" y1="1424" y2="1424" x1="2000" />
        </branch>
        <branch name="R_">
            <wire x2="1616" y1="1296" y2="1296" x1="1600" />
        </branch>
        <branch name="S_">
            <wire x2="1616" y1="1360" y2="1360" x1="1600" />
        </branch>
        <iomarker fontsize="28" x="1600" y="1296" name="R_" orien="R180" />
        <iomarker fontsize="28" x="1600" y="1360" name="S_" orien="R180" />
        <iomarker fontsize="28" x="2320" y="1424" name="Q_" orien="R0" />
    </sheet>
</drawing>