<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="R" />
        <signal name="S" />
        <signal name="Q_" />
        <signal name="XLXN_4" />
        <signal name="Q" />
        <port polarity="Input" name="R" />
        <port polarity="Input" name="S" />
        <port polarity="Output" name="Q_" />
        <port polarity="Output" name="Q" />
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
            <blockpin signalname="R" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_4">
            <blockpin signalname="S" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="Q_" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="R">
            <wire x2="1520" y1="960" y2="960" x1="1280" />
        </branch>
        <branch name="S">
            <wire x2="1520" y1="1360" y2="1360" x1="1280" />
        </branch>
        <branch name="Q_">
            <wire x2="1520" y1="1024" y2="1024" x1="1440" />
            <wire x2="1440" y1="1024" y2="1200" x1="1440" />
            <wire x2="1920" y1="1200" y2="1200" x1="1440" />
            <wire x2="1920" y1="1200" y2="1328" x1="1920" />
            <wire x2="2000" y1="1328" y2="1328" x1="1920" />
            <wire x2="1920" y1="1328" y2="1328" x1="1776" />
        </branch>
        <branch name="Q">
            <wire x2="1840" y1="1120" y2="1120" x1="1360" />
            <wire x2="1360" y1="1120" y2="1296" x1="1360" />
            <wire x2="1520" y1="1296" y2="1296" x1="1360" />
            <wire x2="1840" y1="992" y2="992" x1="1776" />
            <wire x2="1840" y1="992" y2="1120" x1="1840" />
            <wire x2="2000" y1="992" y2="992" x1="1840" />
        </branch>
        <iomarker fontsize="28" x="1280" y="960" name="R" orien="R180" />
        <iomarker fontsize="28" x="1280" y="1360" name="S" orien="R180" />
        <iomarker fontsize="28" x="2000" y="992" name="Q" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1328" name="Q_" orien="R0" />
        <instance x="1520" y="1088" name="XLXI_3" orien="R0" />
        <instance x="1520" y="1424" name="XLXI_4" orien="R0" />
    </sheet>
</drawing>