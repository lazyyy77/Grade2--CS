<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_3" />
        <signal name="B" />
        <signal name="XLXN_5" />
        <signal name="C" />
        <signal name="XLXN_7" />
        <signal name="XLXN_9" />
        <signal name="A" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="Co" />
        <signal name="S" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="Co" />
        <port polarity="Output" name="S" />
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
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
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <block symbolname="xor2" name="XLXI_1">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_3">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="S" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_7">
            <blockpin signalname="XLXN_15" name="I0" />
            <blockpin signalname="XLXN_14" name="I1" />
            <blockpin signalname="XLXN_13" name="I2" />
            <blockpin signalname="Co" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1392" y="976" name="XLXI_1" orien="R0" />
        <instance x="1792" y="1136" name="XLXI_3" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="1680" y1="880" y2="880" x1="1648" />
            <wire x2="1680" y1="880" y2="1008" x1="1680" />
            <wire x2="1792" y1="1008" y2="1008" x1="1680" />
        </branch>
        <branch name="C">
            <wire x2="1360" y1="1072" y2="1072" x1="800" />
            <wire x2="1792" y1="1072" y2="1072" x1="1360" />
            <wire x2="1360" y1="1072" y2="1280" x1="1360" />
            <wire x2="1360" y1="1280" y2="1392" x1="1360" />
            <wire x2="1360" y1="1392" y2="1504" x1="1360" />
            <wire x2="1360" y1="1504" y2="1664" x1="1360" />
            <wire x2="1520" y1="1664" y2="1664" x1="1360" />
            <wire x2="1520" y1="1504" y2="1504" x1="1360" />
        </branch>
        <instance x="1520" y="1408" name="XLXI_4" orien="R0" />
        <instance x="1520" y="1568" name="XLXI_5" orien="R0" />
        <instance x="1520" y="1728" name="XLXI_6" orien="R0" />
        <branch name="B">
            <wire x2="1200" y1="912" y2="912" x1="800" />
            <wire x2="1392" y1="912" y2="912" x1="1200" />
            <wire x2="1200" y1="912" y2="1280" x1="1200" />
            <wire x2="1200" y1="1280" y2="1344" x1="1200" />
            <wire x2="1520" y1="1344" y2="1344" x1="1200" />
            <wire x2="1200" y1="1344" y2="1440" x1="1200" />
            <wire x2="1520" y1="1440" y2="1440" x1="1200" />
        </branch>
        <branch name="A">
            <wire x2="1040" y1="848" y2="848" x1="800" />
            <wire x2="1392" y1="848" y2="848" x1="1040" />
            <wire x2="1040" y1="848" y2="1280" x1="1040" />
            <wire x2="1040" y1="1280" y2="1440" x1="1040" />
            <wire x2="1040" y1="1440" y2="1600" x1="1040" />
            <wire x2="1520" y1="1600" y2="1600" x1="1040" />
            <wire x2="1184" y1="1280" y2="1280" x1="1040" />
            <wire x2="1184" y1="1264" y2="1280" x1="1184" />
            <wire x2="1216" y1="1264" y2="1264" x1="1184" />
            <wire x2="1216" y1="1264" y2="1280" x1="1216" />
            <wire x2="1344" y1="1280" y2="1280" x1="1216" />
            <wire x2="1344" y1="1264" y2="1280" x1="1344" />
            <wire x2="1376" y1="1264" y2="1264" x1="1344" />
            <wire x2="1376" y1="1264" y2="1280" x1="1376" />
            <wire x2="1440" y1="1280" y2="1280" x1="1376" />
            <wire x2="1520" y1="1280" y2="1280" x1="1440" />
        </branch>
        <instance x="1920" y="1600" name="XLXI_7" orien="R0" />
        <branch name="XLXN_13">
            <wire x2="1920" y1="1312" y2="1312" x1="1776" />
            <wire x2="1920" y1="1312" y2="1408" x1="1920" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="1920" y1="1472" y2="1472" x1="1776" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="1920" y1="1632" y2="1632" x1="1776" />
            <wire x2="1920" y1="1536" y2="1632" x1="1920" />
        </branch>
        <branch name="Co">
            <wire x2="2320" y1="1472" y2="1472" x1="2176" />
        </branch>
        <branch name="S">
            <wire x2="2320" y1="1040" y2="1040" x1="2048" />
        </branch>
        <iomarker fontsize="28" x="800" y="848" name="A" orien="R180" />
        <iomarker fontsize="28" x="800" y="912" name="B" orien="R180" />
        <iomarker fontsize="28" x="800" y="1072" name="C" orien="R180" />
        <iomarker fontsize="28" x="2320" y="1040" name="S" orien="R0" />
        <iomarker fontsize="28" x="2320" y="1472" name="Co" orien="R0" />
    </sheet>
</drawing>