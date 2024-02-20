<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Q_" />
        <signal name="XLXN_4" />
        <signal name="Q" />
        <signal name="C" />
        <signal name="S" />
        <signal name="R" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <port polarity="Output" name="Q_" />
        <port polarity="Output" name="Q" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="S" />
        <port polarity="Input" name="R" />
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <block symbolname="nand2" name="XLXI_3">
            <blockpin signalname="Q_" name="I0" />
            <blockpin signalname="XLXN_9" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_4">
            <blockpin signalname="XLXN_10" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="Q_" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_5">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="S" name="I1" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_6">
            <blockpin signalname="R" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="Q_">
            <wire x2="1760" y1="1264" y2="1264" x1="1680" />
            <wire x2="1680" y1="1264" y2="1440" x1="1680" />
            <wire x2="2160" y1="1440" y2="1440" x1="1680" />
            <wire x2="2160" y1="1440" y2="1568" x1="2160" />
            <wire x2="2240" y1="1568" y2="1568" x1="2160" />
            <wire x2="2160" y1="1568" y2="1568" x1="2016" />
        </branch>
        <branch name="Q">
            <wire x2="2080" y1="1360" y2="1360" x1="1600" />
            <wire x2="1600" y1="1360" y2="1536" x1="1600" />
            <wire x2="1760" y1="1536" y2="1536" x1="1600" />
            <wire x2="2080" y1="1232" y2="1232" x1="2016" />
            <wire x2="2080" y1="1232" y2="1360" x1="2080" />
            <wire x2="2240" y1="1232" y2="1232" x1="2080" />
        </branch>
        <instance x="1760" y="1328" name="XLXI_3" orien="R0" />
        <instance x="1760" y="1664" name="XLXI_4" orien="R0" />
        <iomarker fontsize="28" x="2240" y="1232" name="Q" orien="R0" />
        <iomarker fontsize="28" x="2240" y="1568" name="Q_" orien="R0" />
        <instance x="1264" y="1296" name="XLXI_5" orien="R0" />
        <instance x="1264" y="1696" name="XLXI_6" orien="R0" />
        <branch name="C">
            <wire x2="1200" y1="1408" y2="1408" x1="1120" />
            <wire x2="1200" y1="1408" y2="1568" x1="1200" />
            <wire x2="1248" y1="1568" y2="1568" x1="1200" />
            <wire x2="1264" y1="1568" y2="1568" x1="1248" />
            <wire x2="1264" y1="1232" y2="1232" x1="1200" />
            <wire x2="1200" y1="1232" y2="1408" x1="1200" />
        </branch>
        <branch name="S">
            <wire x2="1264" y1="1168" y2="1168" x1="1120" />
        </branch>
        <branch name="R">
            <wire x2="1264" y1="1632" y2="1632" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="1120" y="1168" name="S" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1408" name="C" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1632" name="R" orien="R180" />
        <branch name="XLXN_9">
            <wire x2="1760" y1="1200" y2="1200" x1="1520" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1760" y1="1600" y2="1600" x1="1520" />
        </branch>
    </sheet>
</drawing>