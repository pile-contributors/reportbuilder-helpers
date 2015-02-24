#include <gtest/gtest.h>
#include <reportbuilder/reportbuilder.h>
#include <QTemporaryFile>

class TestUsage : public ::testing::Test {

public:

    TestUsage () {}

    virtual ~TestUsage () {}

    void SetUp(){

    }
    void TearDown(){

    }

};

TEST_F(TestUsage, initial_state) {

    // create temp file
    QTemporaryFile tf;
    ASSERT_TRUE (tf.open ());
    tf.close ();
    tf.remove ();

    {
        ReportBuilder rb (tf.fileName ());

        rb.addHLine(1);
        rb.addEmptyLine ();
        rb.addHLine(2);

        rb.addTitle ("Title 1", 1);
        rb.addTitle ("Title 2", 2);
        rb.addTitle ("Title 3", 3);
        rb.addTitle ("Title 4", 4);
        rb.addTitle ("Title 5", 5);
        rb.addHLine(3);

        rb.addLine ("a line of text a line of text a line of text a line of text");
        rb.add ("a paragraph a paragraph a paragraph a paragraph a paragraph");

        rb.addHLine(4);

        rb.beginTable (4, 5);
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 5; ++c) {
                rb.setTableCell (r, c, QString("Cell R %1 C %2").arg(r).arg(c));
            }
        }
        rb.endTable ();

        rb.addHtml ("<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>");

        rb.beginCode ();
        rb.addLine ("a line of text\na line of text\na line of text\na line of text\n");
        rb.addLine ("another line of text");
        rb.addLine ("another line of text");
        rb.addLine ("another line of text");
        rb.addLine ("another line of text");
        rb.endCode ();

        rb.beginInsert ();
        rb.add ("a paragraph a paragraph a paragraph a paragraph a paragraph");
        rb.endInsert ();

    }

}

