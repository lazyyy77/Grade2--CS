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
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <block symbolname="nor2" name="XLXI_1">
            <blockpin signalname="S" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="Q_" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_2">
            <blockpin signalname="Q_" name="I0" />
            <blockpin signalname="R" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="R">
            <wire x2="1600" y1="1040" y2="1040" x1="1360" />
        </branch>
        <branch name="S">
            <wire x2="1600" y1="1440" y2="1440" x1="1360" />
        </branch>
        <instance x="1600" y="1504" name="XLXI_1" orien="R0" />
        <instance x="1600" y="1168" name="XLXI_2" orien="R0" />
        <branch name="Q_">
            <wire x2="1600" y1="1104" y2="1104" x1="1520" />
            <wire x2="1520" y1="1104" y2="1280" x1="1520" />
            <wire x2="2000" y1="1280" y2="1280" x1="1520" />
            <wire x2="2000" y1="1280" y2="1408" x1="2000" />
            <wire x2="2080" y1="1408" y2="1408" x1="2000" />
            <wire x2="2000" y1="1408" y2="1408" x1="1856" />
        </branch>
        <branch name="Q">
            <wire x2="1920" y1="1200" y2="1200" x1="1440" />
            <wire x2="1440" y1="1200" y2="1376" x1="1440" />
            <wire x2="1600" y1="1376" y2="1376" x1="1440" />
            <wire x2="1920" y1="1072" y2="1072" x1="1856" />
            <wire x2="1920" y1="1072" y2="1200" x1="1920" />
            <wire x2="2080" y1="1072" y2="1072" x1="1920" />
        </branch>
        <iomarker fontsize="28" x="1360" y="1040" name="R" orien="R180" />
        <iomarker fontsize="28" x="1360" y="1440" name="S" orien="R180" />
        <iomarker fontsize="28" x="2080" y="1072" name="Q" orien="R0" />
        <iomarker fontsize="28" x="2080" y="1408" name="Q_" orien="R0" />
    </sheet>
</drawing>